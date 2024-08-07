#include "tile.h"

enum Building {
  None,
  Settlement,
  City
};

struct Point;

struct Edge {
  Tile *upper = nullptr;
  Tile *lower = nullptr;
  Point *next_point = nullptr;
  Point *prev_point = nullptr;
  bool road = false;
};

struct Point {
  Edge *next_edge = nullptr;
  Edge *prev_edge = nullptr;
  Edge *adjacent = nullptr;
  bool port = false;
  Building building = Building::None;
};