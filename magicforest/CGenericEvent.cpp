#include "CGenericEvent.h"

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
	printf("%s\n", this->GetDescription());
	if (Listener && Loot) 
	{
		Listener->GotLoot(Loot);
	}
}


