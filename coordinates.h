#ifndef COORDINATES_H
#define COORDINATES_H

#include <map>
#include <tuple>
#include <vector>

struct AxialCoord {
  int q;  // column
  int r;  // row
  
  AxialCoord() : q(0), r(0) {}
  AxialCoord(int q, int r) : q(q), r(r) {}
  
  bool operator==(const AxialCoord& other) const {
    return q == other.q && r == other.r;
  }
  
  bool operator<(const AxialCoord& other) const {
    if (q != other.q) return q < other.q;
    return r < other.r;
  }
};

// Vertex represents an intersection point where hexagons meet
// Each vertex is defined by its three adjacent hex tiles' axial coordinates
struct Vertex {
  AxialCoord hex1;  // First adjacent hex
  AxialCoord hex2;  // Second adjacent hex
  AxialCoord hex3;  // Third adjacent hex
  int screen_y;     // Screen Y position
  int screen_x;     // Screen X position
  
  Vertex() : screen_y(0), screen_x(0) {}
  Vertex(AxialCoord h1, AxialCoord h2, AxialCoord h3, int y, int x) 
    : hex1(h1), hex2(h2), hex3(h3), screen_y(y), screen_x(x) {}
  
  bool operator<(const Vertex& other) const {
    if (hex1.q != other.hex1.q) return hex1.q < other.hex1.q;
    if (hex1.r != other.hex1.r) return hex1.r < other.hex1.r;
    if (hex2.q != other.hex2.q) return hex2.q < other.hex2.q;
    if (hex2.r != other.hex2.r) return hex2.r < other.hex2.r;
    if (hex3.q != other.hex3.q) return hex3.q < other.hex3.q;
    return hex3.r < other.hex3.r;
  }
};

// HexEdge represents a connection between two vertices (renamed to avoid conflict with edge.h)
struct HexEdge {
  Vertex v1;
  Vertex v2;
  
  HexEdge() {}
  HexEdge(Vertex v1, Vertex v2) : v1(v1), v2(v2) {}
};

#endif
