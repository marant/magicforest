#include <stdio.h>
#include "CGame.h"
#include "CLocation.h"
#include "CBattleEvent.h"
#include "CEndEvent.h"
#include "CGameItem.h"
#include "CGenericEvent.h"

//Initialize the game, create locations, player and monsters
CGame::CGame()
{ 
  //Player
  Player = new CGameCharacter();   
  Player->SetHP(20);
  Player->SetAttackModifier(0.75);

  //Monsters
  CGameCharacter* Orc     = new CGameCharacter();
  CGameCharacter* Bandit  = new CGameCharacter();

	//Loot
  CGameItem* phat = new CGameItem();
  phat->SetName("a can of ES");

  //Events
  CBattleEvent* battle1 = new CBattleEvent(Player, Orc);
  CBattleEvent* battle2 = new CBattleEvent(Player, Bandit);
  CGenericEvent* lootevent = new CGenericEvent();
  CEndEvent* endevent = new CEndEvent();
	lootevent->SetLoot(phat);
  endevent->SetListener(this);

  battle1->SetDescription("As you walk forward an Orc jumps at you through "
                          " a bush!\n");
  battle2->SetDescription("Suddenly a bandit attacks you from behind screaming"
                          " \"GIEF ME UR MONIES, PUNK!\"\n");

  //ORC
  Orc->SetName("an Orc");
  Orc->SetHP(10);
  Orc->SetAttackModifier(0.50);

  //BANDIT 
  Bandit->SetName("a Bandit");
  Bandit->SetHP(15);
  Bandit->SetAttackModifier(0.40);

  //Locations
  CLocation* Location1 = new CLocation();
  CLocation* Location2 = new CLocation();
  CLocation* Location3 = new CLocation();

  Locations.push_back(Location1);
  Locations.push_back(Location2);
  Locations.push_back(Location3);

  //Routes
  Location1->SetNorthRoute(Location2);
  Location2->SetNorthRoute(Location3);

  //initialize Location1
  Location1->SetListener(this);
  Location1->AddEvent(battle1);
  /*Location1->SetDescription("You see an old and dirty road ahead of you."
                           " The road looks like it hasn't been used in ages"
                           " and you can feel that there's something really"
                           " wrong with it...");*/

  //initialize Location2
  Location2->SetListener(this);
	Location2->AddEvent(lootevent);
  Location2->AddEvent(battle2);
  //Location3->SetDescription("You see a small clearing up ahead.");


  //initialize Location3
  Location3->SetListener(this);
  Location3->AddEvent(endevent);
}

CGame::~CGame()
{
	/* delete all locations from the game */
	unsigned int i;
	for (i = 0; i < Locations.size(); i++)
	{
		CLocation* pTempLocation = NULL;
    pTempLocation = Locations[i];
		delete pTempLocation;
	}

	Locations.clear();
}

void CGame::Start()
{
  CurrentLocation = NULL;
  std::string PlayerName;

	//printf("Welcome to Magic Forest, %s!\n", Player.GetName());
  printf("Welcome to Magic Forest!\n");
  this->AskPlayerInfo();
  std::cout << "I see that you're called \"" << Player->GetName() << "\" ";
  std::cout << "Now let's set on our epic journey across the MAGIC FOREST!" << std::endl;

  CurrentLocation = Locations[0];

	while (CurrentLocation)
	{
		/* play the events */
    CurrentLocation->ExecuteEvents();

		/* find out where the player wants to go next */
    if( CurrentLocation )
    {
      CurrentLocation->AskRoute();
    }
	}
}

void CGame::End()
{
	printf("You made it out of the Magic Forest. Congratulations!\n");
  CurrentLocation = NULL;
}

void CGame::AskPlayerInfo()
{
  std::string PlayerName;

  std::cout << "Let me know your name, oh brave hero!" << std::endl;
  std::cout << "Name: ";
  std::cin >> PlayerName;

  
  while( PlayerName.empty() )
  {
    std::cout << "You inserted an invalid name, my hero!" << std::endl;
    std::cout << "Are you perhaps retarded?! I hope your bravery overcomes ";
    std::cout << "This little shortcoming of yours! Now let us try again: ";
    std::cout << "Name: ";
    std::cin >> PlayerName;
  }

  Player->SetName( PlayerName );
}

void CGame::LocationChanged( CLocation* newLocation )
{
  CurrentLocation = newLocation;
}

void CGame::GotLoot( CGameItem* pLoot )
{
	Player->AddToInventory(pLoot);
	pLoot->SetOwner(Player);
	std::cout << pLoot->GetName() << std::endl;
}

void CGame::PlayerDied( CGameCharacter* Player )
{
  std::cout << "You couldn't get out of the magic forest :(" << std::endl; 
}

void CGame::GameEnded()
{
  End();
}
