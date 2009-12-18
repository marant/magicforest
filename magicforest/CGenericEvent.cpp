#include "CGenericEvent.h"
#include <iostream>

CGenericEvent::CGenericEvent()
 : IEvent()
{
	this->Loot = NULL;
}

CGenericEvent::~CGenericEvent()
{

}

int CGenericEvent::RunEvent()
{
	std::cout << this->GetDescription() << std::endl;
	if (Listener && Loot) 
	{
		Listener->GotLoot(Loot);
	}
}


