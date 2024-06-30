#include "catan.h"
using namespace std;

// int Catan::random(int lower, int upper) {
//   mt19937 mt(random_device{}());
//   uniform_int_distribution<int> dist(lower, upper);
//   return dist(mt);
// }

void Catan::generateMap() {
  cout << "                             /    \\\n";
  cout << "                            /______\\\n";
  cout << "                           /        \\\n";
  cout << "                          /          \\\n";
  cout << "            ____ ________/            \\\n";
  cout << "                /        \\            /\n";
  cout << "            \\  /          \\          /\n";
  cout << "      _______\\/            \\________/\n";
  cout << "     /        \\            /        \\\n";
  cout << "    /          \\          /          \\\n";
  cout << "   /            \\________/            \\\n";
  cout << "   \\            /        \\            /\n";
  cout << "    \\          /          \\          /\n";
  cout << " ____\\________/            \\________/\n";
  cout << "     /        \\            /        \\\n";
  cout << " \\  /          \\          /          \\\n";
  cout << "  \\/            \\________/            \\\n";
  cout << "   \\            /        \\            /\n";
  cout << "    \\          /          \\          /\n";
  cout << "     \\________/            \\________/\n";
  cout << "     /        \\            /        \\\n";
  cout << "    /          \\          /          \\\n";
  cout << "   /            \\________/            \\\n";
  cout << "  /\\            /        \\            /\n";
  cout << " /  \\          /          \\          /\n";
  cout << " ____\\________/            \\________/\n";
  cout << "              \\            /        \\\n";
  cout << "               \\          /          \\\n";
  cout << "                \\________/            \\\n";
  cout << "                 \\      /\\            /\n";
  cout << "                  \\    /  \\          /\n";
  cout << "                           \\________/\n";
}

int main() {
  int players = 4;
  cout << "Welcome to The Settlers of Catext!\n";
  cout << "Please enter the total number of players: ";
  // cin >> players;
  cout << "\nYour game will have " << players << " players.\n";
  Catan catan(players);
  catan.generateMap();
  return 0;
};