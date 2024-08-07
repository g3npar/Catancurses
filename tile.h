enum class Resource {
  Desert,
  Brick,
  Lumber,
  Ore,
  Grain,
  Wool,
  None
};

enum Direction {
  N,
  NE,
  SE,
  S,
  SW,
  NW
};

struct Tile {
  Resource resource = Resource::None;
  int roll;
  int idx;
  
  bool robber = false;
  std::vector<Tile*> tiles = {
    nullptr, // N
    nullptr, // NE
    nullptr, // SE
    nullptr, // S
    nullptr, // SW
    nullptr, // NW
  };

  Tile(Resource resource, int roll, int idx) : resource(resource), roll(roll), idx(idx) {};
};

