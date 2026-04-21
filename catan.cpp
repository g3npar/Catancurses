#include <ncurses.h>
#include <unistd.h>
#include <algorithm>
#include "catan.h"

void printSingleHex(int y, int x, Island* island = nullptr) {
  mvprintw(y, x, "\\E______E/");
  mvprintw(y + 1, x, "/        \\");
  mvprintw(y + 2, x - 1, "/          \\");
  mvprintw(y + 3, x - 3, "E/            \\E");
  mvprintw(y + 4, x - 2, "\\            /");
  mvprintw(y + 5, x - 1, "\\          /");
  mvprintw(y + 6, x, "\\E______E/");
  
  // Store empty space coordinates if island pointer is provided
  if (island != nullptr) {
    island->addEmptySpace(y, x + 1);       // Top-left E
    island->addEmptySpace(y, x + 8);       // Top-right E
    island->addEmptySpace(y + 3, x - 3);   // Left E
    island->addEmptySpace(y + 3, x + 14);  // Right E
    island->addEmptySpace(y + 6, x + 1);   // Bottom-left E
    island->addEmptySpace(y + 6, x + 8);   // Bottom-right E
  }
}

void Catan::printMap() {
  // Print the legend at the top of the map
  mvprintw(0, 1, "----LEGEND----");
  mvprintw(1, 1, "# = Settlement");
  mvprintw(2, 1, "$ = City");
  mvprintw(3, 1, "B = Brick");
  mvprintw(4, 1, "L = Lumber");
  mvprintw(5, 1, "O = Ore");
  mvprintw(6, 1, "G = Grain");
  mvprintw(7, 1, "W = Wool");
  mvprintw(8, 1, "D = Desert");
  mvprintw(9, 1, "E = Empty");

  island.clearEmptySpaces();

  // Print the hexes in a grid
  if (num_players <= 4) {
    // Print the base map for 2-4 players
    int y = box_center_y + 3;
    int x = (getmaxx(stdscr) / 2) - 30;
    int k = 0;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < base_map[i]; ++j) {
        printSingleHex(y, x, &island);
        y -= 6;
      }
      k = (i >= 2) ? k - 1 : k + 1;
      y = box_center_y + 3 + (k * 3);
      x += 11;
    }
  } else if (num_players > 4 && num_players <= 6) {
    // Print the expanded map for 5-6 players
    int y = box_center_y + 3;
    int x = (getmaxx(stdscr) / 2) - 34;
    int k = 0;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < expanded_map[i]; ++j) {
        printSingleHex(y, x, &island);
        y -= 6;
      }
      k = (i >= 3) ? k - 1 : k + 1;
      y = box_center_y + 3 + (k * 3);
      x += 11;
    }
  } else {
    // Print map according to the number of players
    int y = box_center_y + 3;
    int x = (getmaxx(stdscr) / 2) - (num_players / 4) * 16;
    int k = 0;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < expanded_map[i]; ++j) {
        printSingleHex(y, x, &island);
        y -= 6;
      }
      k = (i >= 3) ? k - 1 : k + 1;
      y = box_center_y + 3 + (k * 3);
      x += 11;
    }
  }
}

void Catan::setHexes() {
  island.createMap();
}

void Catan::printAxes() {
  // Display axes explanation in bottom left corner
  int max_y = getmaxy(stdscr);
  int start_y = max_y - 10;  // Start 10 lines from bottom
  int start_x = 2;
  
  // Print axes diagram
  init_pair(5, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(5));
  
  mvprintw(start_y, start_x, "=== AXES ===");
  start_y += 2;
  
  // Draw q-axis (horizontal to the right)
  mvprintw(start_y, start_x, "q-axis -->");
  start_y++;
  mvprintw(start_y, start_x, "(increases right)");
  start_y += 2;
  
  // Draw r-axis (diagonal down-left)
  mvprintw(start_y, start_x, "r-axis");
  start_y++;
  mvprintw(start_y, start_x + 1, "\\");
  start_y++;
  mvprintw(start_y, start_x + 2, "\\");
  start_y++;
  mvprintw(start_y, start_x + 3, "v");
  mvprintw(start_y, start_x + 5, "(increases down)");
  
  attroff(COLOR_PAIR(5));
}

int main() {
  // Initializing ncurses and the Catan class
  Catan catan = Catan(4);
  initscr();
  start_color();
  refresh();

  int x, y;
  getmaxyx(stdscr, y, x);

  // Center the logo dynamically
  int logo_radius = 40;
  int logo_start_x = (x / 2) - logo_radius;

  // Creating game logo
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  mvprintw(0, logo_start_x,     "_________         __");
  mvprintw(1, logo_start_x, "\\_   ___ \\_____ _/  |______");
  mvprintw(2, logo_start_x, "/    \\  \\/\\__  \\\\   __\\__  \\ ");
  mvprintw(3, logo_start_x, "\\     \\____/ __ \\|  |  / __ \\ ");
  mvprintw(4, logo_start_x, "\\______  (____  /__| (____  ");
  mvprintw(5, logo_start_x, "       \\/     \\/          \\/");
  attron(COLOR_PAIR(2));
  mvprintw(1, logo_start_x + 28, "  ____   ____  __ _________  ______ ____   ______");
  mvprintw(2, logo_start_x + 28, " /    \\_/ ___\\|  |  \\_  __ \\/  ___// __ \\ /  ___/");
  mvprintw(3, logo_start_x + 28, "|   |  \\  \\___|  |  /|  | \\/\\___ \\\\  ___/ \\___ \\ ");
  mvprintw(4, logo_start_x + 28, "/___|  /\\___  >____/ |__|  /____  >\\___  >____  >");
  mvprintw(5, logo_start_x + 28, "     \\/     \\/                  \\/     \\/     \\/ ");
  attron(COLOR_PAIR(3));

  // Creating the map interface
  catan.box_height = (3 * y) / 4;
  catan.box_width = x / 2;
  catan.box_start_y = (y - catan.box_height) / 2;
  catan.box_start_x = (x - catan.box_width) / 2;
  catan.box_center_y = y / 2;
  catan.box_center_x = x / 2;
  catan.printMap();
  catan.printAxes();

  refresh();

  getch();
  endwin();
  return 0;
};