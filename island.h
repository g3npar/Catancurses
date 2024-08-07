#ifndef ISLAND_H
#define ISLAND_H

#include <unordered_set>
#include <vector>
#include "randNum.h"
#include "edge.h"
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

    // REQUIRES: at least one resource count is above 0
    // EFFECTS: returns a random resource and then updates its respective count
    Resource generateResource();

    // REQUIRES: rolls isn't empty
    // MODIFIES: rolls
    // EFFECTS: returns a random roll number and then deletes it from rolls
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

    void createMap();

    void deleteMap(Tile* tile, std::unordered_set<Tile*>& visited);
};

#endif