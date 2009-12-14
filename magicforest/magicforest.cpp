#include "CGame.h"
#include <iostream>

int main(int argc, const char *argv[])
{
  CGame game;

  #ifdef DEBUG
    std::cout << "DEBUGGING IS ENABLED!" << std::endl;
  #endif
  game.Start();

  return 0;
}
