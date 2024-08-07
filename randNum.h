#include <random>

// REQUIRES: lower <= upper, lower > 0, upper > 0
// MODIFIES: random_device
// EFFECTS: returns a random integer within the given bounds (inclusive)
inline int randNum(int lower, int upper) {
  std::mt19937 mt(std::random_device{}());
  std::uniform_int_distribution<int> dist(lower, upper);
  return dist(mt);
}