#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stdlib.h>
#include "player.h"
using std::string, std::vector;

class Catan {
  private:
    int num_players;
    string map;
  
    // // REQUIRES: lower <= upper
    // // EFFECTS: generates a random number between lower and upper
    // int random(int lower, int upper);
  public:
    Catan(int np) : num_players(np) { }

    // MODIFIES: cout
    // EFFECTS: generates and sets the first instance of the map
    void generateMap();

    // // MODIFIES: cout
    // // EFFECTS: prints the map
    // void printMap();
};

#endif