#include "CGenericEvent.h"

CGenericEvent::CGenericEvent()
 : IEvent()
{

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


