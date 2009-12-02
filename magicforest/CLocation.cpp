#include <stdio.h>
#include "CLocation.h"
#include "IEvent.h"


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
		IEvent* pTempEvent = NULL;
    pTempEvent = Events[i];
		delete pTempEvent;
	}

	Events.clear();
}


void CLocation::AddEvent(IEvent* pEvent)
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
	unsigned int choice, fail=1;
	/* loop until player gets it right */
	while (fail != 0)
	{
		printf("Where do you want to go?\n");
		/* test if route exists, otherwise don't show the option */
		if( pNorthRoute ) 
      printf("1: North\n");

		if( pEastRoute ) 
      printf("2: East\n");
    
    if( pSouthRoute )
      printf("3: South\n");

		if( pWestRoute )
      printf("4: West\n");

		scanf("%d",choice);

		switch (choice) 
		{
			/* check that the player won't accidentally 
			 * push the wrong button and cause null-pointer madness */
			case 1:
				if( pNorthRoute )
         return pNorthRoute;

        fail=1;
				break;

			case 2:
				if( pEastRoute )
          return pEastRoute;

        fail=1;
				break;

			case 3:
				if( pSouthRoute )
         return pSouthRoute;
        
        fail=1;
				break;

			case 4:
				if( pWestRoute )
          return pWestRoute;
        fail=1;
				break;

			default:
				printf("Invalid option!\n");
				fail = 1;
				break;
		}
	}
}
