/**
 * Author: Juhani Alanko
 * Date: 2009-11-23
 * Description: A class that is used to create a location in the game.
 */

#ifndef __CLOCATION_H__

#define __CLOCATION_H__

#include <vector.h>

class CLocation 
{
public:
	CLocation ();
	virtual ~CLocation ();

	inline void SetNorthRoute(CLocation* pLocation) { pNorthRoute = pLocation }
	inline void SetEastRoute(CLocation* pLocation) { pEastRoute = pLocation }
	inline void SetSouthRoute(CLocation* pLocation) { pSouthRoute = pLocation }
	inline void SetWestRoute(CLocation* pLocation) { pWestRoute = pLocation }

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
