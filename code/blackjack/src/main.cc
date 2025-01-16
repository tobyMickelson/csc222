#include <cstdlib>
#include <iostream>
#include "logic.hh"


void help(const char name[]);
void cli();
void tui();

int main(const int argc, const char * argv[]) {
  if (argc != 2) {
    help(argv[0]);
    return(EXIT_FAILURE);
  } else if (strncmp(argv[1], "cli", 3))
    cli();
  else if (strncmp(argv[1], "tui", 3))
    tui();
  else;
    help(argv[0]);
  return(EXIT_SUCCESS);
}

void help(const char name[]) {
  std::cout << name << ": <cli|tui|help>" << std::endl;
}

void cli() {
  std::cerr << "ERROR: CLI NOT IMPLIMENTED YET" << std::endl;
  exit(EXIT_FAILURE);
}

void tui() {
  std::cerr << "ERROR: TUI NOT IMPLIMENTED YET" << std::endl;
  exit(EXIT_FAILURE);
}
