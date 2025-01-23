#include <cstdlib>
#include <ncurses.h>
#include <vector>
#include "cards.hpp"
#include "logic.hpp"

#define PAIR_NORMAL 1
#define PAIR_ALERT 2
#define NEWLINE "\n"


void pretty_print(std::vector<std::vector<Card> > players) {
  for (int player = 0; player < players.size(); player++) {
    for (int card = 0; card < players[player].size(); card++) {
      printw("%s", players[player][card].initials().data());
      if (card + 1 != players[player].size())
        printw(" ");
      else if (player + 1 != players.size())
        printw("   :   ");
    }
  }
  printw(NEWLINE);
  refresh();
}

std::string pretty_to_string(std::vector<std::vector<Card> > players) {
  std::string output = "";
  
  for (int player = 0; player < players.size(); player++) {
    for (int card = 0; card < players[player].size(); card++) {
      output += players[player][card].initials().data();
      if (card + 1 != players[player].size())
        output += " ";
      else if (player + 1 != players.size())
        output += "   :   ";
    }
  }

  return output;
}

std::vector<bool> pretty_hit(int players) {
  std::vector<bool> hits;
  char character;
  bool do_loop = true;

  echo();
  
  for (int player = 0; player < players; player++) {
    printw("Player %d, would you like to hit [y/n]: ", player);
    refresh();
    character = getch();
    printw(NEWLINE);
    refresh();
    
    switch (character) {
      case '1':
      case 'Y':
      case 'y':
        hits.push_back(true);
        break;
      case '0':
      case 'N':
      case 'n':
        hits.push_back(false);
        break;
      default:
        player--;
    }
  }

  noecho();

  return hits;
}

int get_players() {
  int players = 0;

  do {
    printw("Enter number of players (2-9): ");
    refresh();
    echo();
    players = getch() - '0';
    {
      printw("%d", players);
      refresh();
    }
    noecho();
  
    if (players == 45) {
      endwin();
      exit(EXIT_SUCCESS);
    } else if (players < 2 || players > 9) {
      players = 0;
      attrset(COLOR_PAIR(PAIR_ALERT));
      printw("   Between 2 and 9 players are required (press any key to exit)" NEWLINE);
      attrset(COLOR_PAIR(0));
      refresh();
    }
  } while (players == 0);

  printw(NEWLINE);
  refresh();
  
  return players;
}

void run_pretty_cli() {
  std::vector<bool> hits;

  setlocale(LC_ALL, "");
  initscr();
  noecho();
  
  int players = get_players();
  
  if (has_colors()) {
    start_color();
    init_pair(PAIR_NORMAL, COLOR_WHITE, COLOR_BLACK);
    init_pair(PAIR_ALERT, COLOR_RED, COLOR_BLACK);
  }
  
  Blackjack game = Blackjack(players);
  while (true) {
    pretty_print(game.players);
    hits = pretty_hit(players);
    if (std::none_of(hits.begin(), hits.end(), [](bool b) {return b;}))
      break;
    game.hit(hits);
    if (game.error) {
      attrset(COLOR_PAIR(PAIR_ALERT));
      printw(NEWLINE "%s (press any key to exit)" NEWLINE, game.error_message.data());
      attrset(COLOR_PAIR(0));
      refresh();
      getch();
      endwin();
      exit(EXIT_FAILURE);
    }
  }

  endwin();
}
