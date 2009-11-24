#include <stdio.h>
#include "CLocation.h"


CLocation::CLocation()
{
	/* constructor */
}


CLocation::~CLocation()
{
	/* delete all events from a location */
	unsigned int i;
	for (i = 0; i < Events.size(); i++)
	{
		CEvent* pTempEvent = Events[i];
		delete pTempEvent;
	}

	Events.clear();
}


void CLocation::AddEvent(CEvent* pEvent)
{
	Events.push_back(pEvent);
}


/* 
 * Goes through the event list, hitting the play buttons
 */
void CLocation::ExecuteEvents()
{
	unsigned int i;
	for (i = 0; i < Events.size(); i++)
	{
		Events[i]->RunEvent();
	}
}

/*
 * Asks the player where s/he wants to go next
 * and returns a pointer to the next location
 */
CLocation* CLocation::AskRoute()
{
	unsigned int choice, fail=0;
	/* loop until player gets it right */
	while (!fail)
	{
		printf("Where do you want to go?\n");
		/* test if route exists, otherwise don't show the option */
		pNorthRoute ? printf("1: North\n") : ;
		pEastRoute ? printf("2: East\n") : ;
		pSouthRoute ? printf("3: South\n") : ;
		pWestRoute ? printf("4: West\n") : ;
		scanf("%d",choice);

		switch (choice) 
		{
			/* check that the player won't accidentally 
			 * push the wrong button and cause null-pointer madness */
			case 1:
				pNorthRoute ? return pNorthRoute : fail=1;
				break;
			case 2:
				pEastRoute ? return pEastRoute : fail=1;
				break;
			case 3:
				pSouthRoute ? return pSouthRoute : fail=1;
				break;
			case 4:
				pWestRoute ? return pWestRoute : fail=1;
				break;
			default:
				printf("Invalid option!\n");
				fail = 1;
				break;
		}
	}
}
