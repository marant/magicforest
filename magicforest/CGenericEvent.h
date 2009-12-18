/**
 * Author: Juhani "argontus" Alanko
 * Date: 2009-12-18
 * Description: 
 * 
 * A generic event class that implements IEvent. Describes something
 * and gives loot.
 * 
 */

#ifndef __CGENERICEVENT_H__
#define __CGENERICEVENT_H__

#include "IEvent.h"

class CGameItem;

class CGenericEvent : public IEvent
{
public:
	CGenericEvent ();
	virtual ~CGenericEvent ();

	inline void SetLoot(CGameItem* pLoot) { Loot = pLoot; }
	int RunEvent();

private:
	CGameItem* Loot;	
};

#endif /* __CGENERICEVENT_H__ */
