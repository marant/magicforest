#include "../CLocation.h"
#include "../IEvent.h"
#include "../CBattleEvent.h"
#include "../CGameCharacter.h"
#include "CTestEvent.h"

int main(int argc, const char *argv[])
{
	CGameCharacter* player = new CGameCharacter();
  CGameCharacter* jonne = new CGameCharacter();

  player->SetName("Player");
  player->SetHP(20);
  player->SetAttackModifier(1.75);

  jonne->SetHP(10);
  jonne->SetName("an angry Jonne");
  jonne->SetAttackModifier(1.50);

	CLocation* pLocation1 = new CLocation();
  CLocation* pLocation2 = new CLocation();

  CTestEvent* test = new CTestEvent();
  CTestEvent* test2 = new CTestEvent();
  CBattleEvent* battle = new CBattleEvent(player, jonne);

  test->SetDescription("Spudrö spördööö :-----DDD");
  test2->SetDescription("You find a strange sign. It reads:\n"
												"fuck you,\n"
												"regards, kickey the mouse");

  pLocation1->AddEvent(test);
  pLocation2->AddEvent(test2);
	pLocation2->AddEvent(battle);
  pLocation1->SetNorthRoute(pLocation2);

  pLocation1->ExecuteEvents();
	pLocation1->AskRoute();
	
	pLocation2->ExecuteEvents();

	return 0;
}
