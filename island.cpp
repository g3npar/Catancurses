#include "island.h"

int mod(int a, int b) {
  return ((a % b) + b) % b;
}

Resource Island::generateResource() {
  while (true) {
    switch(randNum(0, 5)) {
      case 0:
        if (desert_count > 0) {
          desert_count--;
          return Resource::Desert;
        }
        break;
      case 1:
        if (brick_count > 0) {
          brick_count--;
          return Resource::Brick;
        }
        break;
      case 2:
        if (lumber_count > 0) {
          lumber_count--;
          return Resource::Lumber;
        }
        break;
      case 3:
        if (ore_count > 0) {
          ore_count--;
          return Resource::Ore;
        }
        break;
      case 4:
        if (grain_count > 0) {
          grain_count--;
          return Resource::Grain;
        }
        break;
      case 5:
        if (wool_count > 0) {
          wool_count--;
          return Resource::Wool;
        }
        break;
    }
  }
  return Resource::None;
}

int Island::generateRoll() {
  if (rolls.size() - 1 == 0)
    return rolls[0];
  size_t i = randNum(0, int(rolls.size() - 1));
  int val = rolls[i];
  rolls.erase(rolls.begin() + i);
  return val;
}

Tile* Island::generateTile() {
  Resource r = generateResource();
  Tile *newTile = new Tile{r, (r == Resource::Desert) ? 0 : generateRoll(), IDX++};
  return newTile;
}

void Island::createMap() {
  if (layer_count < 1)
    throw std::invalid_argument("Layers must be 1 or more");
  
  root_tile = generateTile();
  root_tile->q = 0;  // Center tile at origin (0, 0)
  root_tile->r = 0;
  coord_to_tile[{0, 0}] = root_tile;
  all_tiles.push_back(root_tile);
  
  std::vector<Tile *> outerRing = {root_tile};
  
  // Direction vectors for axial coordinates
  // N: (0, -1), NE: (+1, -1), SE: (+1, 0), S: (0, +1), SW: (-1, +1), NW: (-1, 0)
  int dq[] = {0, 1, 1, 0, -1, -1};  // q offset for each direction
  int dr[] = {-1, -1, 0, 1, 1, 0};  // r offset for each direction
  
  for (int layer = 1; layer < layer_count; layer++) {
    std::vector<Tile *> generatedTiles;
    for (const auto &t : outerRing) {
      for (int dir = N; dir <= NW; dir++) {
        if (t->tiles[dir] != nullptr) 
          continue;

        // Calculate new tile coordinates based on direction
        int new_q = t->q + dq[dir];
        int new_r = t->r + dr[dir];
        
        // Check if tile already exists at this coordinate
        auto coord_key = std::make_pair(new_q, new_r);
        Tile* newTile = nullptr;
        
        if (coord_to_tile.find(coord_key) != coord_to_tile.end()) {
          // Tile already exists, use it
          newTile = coord_to_tile[coord_key];
        } else {
          // Generate new tile
          newTile = generateTile();
          newTile->q = new_q;
          newTile->r = new_r;
          coord_to_tile[coord_key] = newTile;
          all_tiles.push_back(newTile);
          generatedTiles.push_back(newTile);
        }
        
        t->tiles[dir] = newTile;
        newTile->tiles[mod(dir + 3, 6)] = t; 

        // Set previous tiles to match
        auto counterClockwise = mod(dir - 1, 6);
        auto clockwise = mod(dir + 1, 6);

        auto getEdge = [](int firstDir, int secondDir) {
          return std::make_pair(mod(firstDir + 2, 6), mod(secondDir - 2, 6));
        };

        if (t->tiles[counterClockwise] != nullptr) {
          auto first = t->tiles[counterClockwise];
          auto second = newTile;

          auto edge = getEdge(counterClockwise, dir);
          first->tiles[edge.first] = second;
          second->tiles[edge.second] = first;
        }

        if (t->tiles[clockwise] != nullptr) {
          auto first = newTile;
          auto second = t->tiles[clockwise];

          auto edge = getEdge(dir, clockwise);
          first->tiles[edge.first] = second;
          second->tiles[edge.second] = first;
        }
      }
    }
    outerRing = generatedTiles;
  }
}

void Island::deleteMap(Tile* tile, std::unordered_set<Tile*>& visited) {
  // If tile is nullptr or already visited, return
  if (!tile || visited.count(tile))
    return;
  visited.insert(tile);
  for (auto* neighbor : tile->tiles) {
    if (neighbor)
      deleteMap(neighbor, visited);
  }
  delete tile;
}