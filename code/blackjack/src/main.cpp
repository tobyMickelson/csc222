#include <cstdlib>
#include <iostream>
#include "cli.hpp"


void help(const std::string name);
void cli();
void tui();

int main(const int argc, const char * argv[]) {
  if (argc != 2) {
    help(std::string(argv[0]));
    return(EXIT_FAILURE);
  } else if (std::string(argv[1]) == "cli") {
    cli();
  } else if (std::string(argv[1]) == "tui") {
    tui();
  } else {
    help(argv[0]);
  }
  return(EXIT_SUCCESS);
}

void help(const std::string name) {
  std::cout << name << ": <cli|tui|help>" << std::endl;
}

void cli() {
  //run_cheap_cli(3);
  std::cerr << "ERROR: CLI NOT IMPLIMENTED YET" << std::endl;
  exit(EXIT_FAILURE);
}

void tui() {
  std::cerr << "ERROR: TUI NOT IMPLIMENTED YET" << std::endl;
  exit(EXIT_FAILURE);
}
