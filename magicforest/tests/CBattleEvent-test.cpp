#include <iostream>

#include "../CBattleEvent.h"
#include "../CGameCharacter.h"

int main(int argc, const char *argv[])
{
  CGameCharacter* player = new CGameCharacter();
  CGameCharacter* orc = new CGameCharacter();
  CBattleEvent battle(player, orc);

  player->SetName("Player");
  player->SetHP(20);
  player->SetAttackModifier(0.75);

  orc->SetHP(10);
  orc->SetName("an Orc");
  orc->SetAttackModifier(0.50);

  battle.RunEvent();

  return 0;
}
