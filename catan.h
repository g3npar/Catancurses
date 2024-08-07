#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "island.h"
using std::string, std::vector;

class Catan {
  private:
    int num_players;
    string map;
    Island island;
    int start_x = 25;
    int start_y = 53;

    void startHex();
  public:
    Catan(int np) : num_players(np) { }

    // MODIFIES: cout
    // EFFECTS: prints the map
    void printMap();
};