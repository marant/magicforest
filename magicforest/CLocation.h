/*
 * Author: Juhani "argontus" Alanko
 * Date: 2009-11-23
 * Description: 
 *
 * A location class to be used as a container and player for CEvents.
 * Contains certain routes where the player can go on their epic journey
 * after going through all the events in the location.
 *
 */

#ifndef __CLOCATION_H__

#define __CLOCATION_H__

#include <vector.h>

class CLocation 
{
public:
	CLocation ();
	virtual ~CLocation ();

	/* set functions, given a pointer as a parameter */
	inline void SetNorthRoute(CLocation* pLocation) { pNorthRoute = pLocation }
	inline void SetEastRoute(CLocation* pLocation) { pEastRoute = pLocation }
	inline void SetSouthRoute(CLocation* pLocation) { pSouthRoute = pLocation }
	inline void SetWestRoute(CLocation* pLocation) { pWestRoute = pLocation }

	/* get functions, returns a pointer to location */
	inline CLocation* GetNorthRoute() { return pNorthLocation }
	inline CLocation* GetEastRoute() { return pEastLocation }
	inline CLocation* GetSouthRoute() { return pSouthLocation }
	inline CLocation* GetWestRoute() { return pWestLocation }

	void AddEvent(CEvent* pEvent);
	void ExecuteEvents();
	CLocation* AskRoute();

private:
	CLocation* pNorthRoute, pEastRoute, pSouthRoute, pWestRoute;
	std::vector<CEvent*> Events;
};

#endif /* __CLOCATION_H__ */
