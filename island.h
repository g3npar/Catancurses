#ifndef ISLAND_H
#define ISLAND_H

#include <unordered_set>
#include <vector>
#include <map>
#include "randNum.h"
#include "edge.h"
#include "coordinates.h"
#include <stdexcept>
using namespace std;


class Island {
  private:
    vector<int> rolls = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    Tile *root_tile;
    int layer_count = 3;
    int desert_count = 1;
    int brick_count = 3;
    int lumber_count = 4;
    int ore_count = 3;
    int grain_count = 4;
    int wool_count = 4;
    int IDX = 0;
    vector<pair<int, int>> empty_spaces;
    map<pair<int, int>, Tile*> coord_to_tile;  // Maps (q,r) to Tile pointer
    vector<Tile*> all_tiles;  // List of all tiles for easy iteration

    Resource generateResource();
    int generateRoll();
    Tile* generateTile();
  public:
    Island() { 
      createMap(); 
    }

    ~Island() { 
      std::unordered_set<Tile*> visited;
      deleteMap(root_tile, visited);
    };

    Tile * getRoot() {
      return root_tile;
    }

    void addEmptySpace(int y, int x) {
      empty_spaces.push_back({y, x});
    }

    const vector<pair<int, int>>& getEmptySpaces() const {
      return empty_spaces;
    }

    void clearEmptySpaces() {
      empty_spaces.clear();
    }
    
    // Coordinate system methods
    Tile* getTileAt(int q, int r) {
      auto it = coord_to_tile.find({q, r});
      return (it != coord_to_tile.end()) ? it->second : nullptr;
    }
    
    const vector<Tile*>& getAllTiles() const {
      return all_tiles;
    }
    
    void printCoordinateMap();  // Debug function to print all coordinates

    void createMap();
    void deleteMap(Tile* tile, std::unordered_set<Tile*>& visited);
};

#endif