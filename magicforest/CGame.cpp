#include <stdio.h>
#include "CGame.h"

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

	printf("Welcome to Magic Forest, %s!\n", Player.GetName());

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
