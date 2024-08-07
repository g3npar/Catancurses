#include "catan.h"
using namespace std;

void Catan::startHex() {
  move(start_x, start_y);
  printw("\\E______E/");
  move(start_x + 1, start_y);
  printw("/        \\");
  move(start_x + 2, start_y - 1);
  printw("/          \\");
  move(start_x + 3, start_y - 3);
  printw("E/            \\E");
  move(start_x + 4, start_y - 2);
  printw("\\            /");
  move(start_x + 5, start_y - 1);
  printw("\\          /");
  move(start_x + 6, start_y);
  printw("\\E______E/");
}

void Catan::printMap() {
  startHex();
}

int main() {
  Catan catan(4);
  initscr();
  start_color();
  refresh();

  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  move(2, 0);
  attron(COLOR_PAIR(1));
  printw("                   _________         __\n");
  printw("                   \\_   ___ \\_____ _/  |______\n");
  printw("                   /    \\  \\/\\__  \\\\   __\\__  \\ \n");
  printw("                   \\     \\____/ __ \\|  |  / __ \\ \n");
  printw("                    \\______  (____  /__| (____  \n");
  printw("                           \\/     \\/          \\/\n");
  attron(COLOR_PAIR(2));
  move(3, 48);
  printw("  ____   ____  __ _________  ______ ____   ______\n");
  move(4, 48);
  printw(" /    \\_/ ___\\|  |  \\_  __ \\/  ___// __ \\ /  ___/\n");
  move(5, 48);
  printw("|   |  \\  \\___|  |  /|  | \\/\\___ \\\\  ___/ \\___ \\ \n");
  move(6, 48);
  printw("/___|  /\\___  >____/ |__|  /____  >\\___  >____  >\n");
  move(7, 48);
  printw("     \\/     \\/                  \\/     \\/     \\/ \n");
  attron(COLOR_PAIR(3));
  catan.printMap();

  int x, y;
  getmaxyx(stdscr, y, x);

  WINDOW *map = nullptr;
  map = newwin(40, 100, (y / 2) - 20, (x / 2) - 50);
  box(map, 0, 0);
  wrefresh(map);

  getch();
  endwin();
  return 0;
};