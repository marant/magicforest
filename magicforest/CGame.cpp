#include <stdio.h>
#include "CGame.h"
#include "CLocation.h"

CGame::CGame()
{  
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
	unsigned int CharacterLocation = 0, i;
  std::string PlayerName;

	//printf("Welcome to Magic Forest, %s!\n", Player.GetName());
  printf("Welcome to Magic Forest!\n");
  this->AskPlayerInfo();
  std::cout << "I see that you're called \"" << Player.GetName() << "\" ";
  std::cout << "Now let's set on our epic journey across the MAGIC FOREST!" << std::endl;

	while (CharacterLocation >= 0)
	{
		/* play the events */
		Locations[CharacterLocation]->ExecuteEvents();

		/* find out where the player wants to go next */
		CLocation* pNextLocation = NULL;
		pNextLocation = Locations[CharacterLocation]->AskRoute();

		/* finds the corresponding location from the vector */
		for (i = 0; i < Locations.size(); i++)
		{
			if (Locations[i] == pNextLocation) 
			{
				CharacterLocation = i;
			}
		}
	}
}

void CGame::End()
{
	printf("You made it out of the Magic Forest. Congratulations!\n");
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

  Player.SetName( PlayerName );
}

void CGame::LocationChanged( const CLocation* newLocation )
{

}

void CGame::PlayerDied( const CGameCharacter* Player )
{
 
}
