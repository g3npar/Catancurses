#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "island.h"
#include "coordinates.h"
using std::string, std::vector;

class Catan {
  public:
    Catan(int np) : num_players(np) {};
    int box_start_x;
    int box_start_y;
    int box_center_x;
    int box_center_y;
    int box_height;
    int box_width;

    void printMap();
    void setHexes();
    void printAxes();

  private:
    std::vector<int> base_map = {3, 4, 5, 4, 3};
    std::vector<int> expanded_map = {4, 5, 6, 6, 5, 4};
    int num_players = 4;
    Island island;
    std::map<std::pair<int, int>, std::pair<int, int>> tile_screen_positions;
    std::map<std::tuple<int, int, int>, Vertex> vertices;
};

#endif // CATAN_H