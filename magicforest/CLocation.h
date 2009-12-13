/*
 * Author: Juhani "argontus" Alanko
 * Date: 2009-11-23
 * Description: 
 *
 * A location class to be used as a container and player for IEvents.
 * Contains certain routes where the player can go on their epic journey
 * after going through all the events in the location.
 *
 */

#ifndef __CLOCATION_H__

#define __CLOCATION_H__

#include <vector>
#include <iostream>

class IEvent;
class IEventNotifier;

class CLocation 
{
public:
	CLocation ();
	virtual ~CLocation ();

	/* set functions, given a pointer as a parameter */
	inline void SetNorthRoute( CLocation* pLocation) { this->pNorthRoute = pLocation; }
	inline void SetEastRoute(CLocation* pLocation) { this->pEastRoute = pLocation; }
	inline void SetSouthRoute(CLocation* pLocation) { this->pSouthRoute = pLocation; }
	inline void SetWestRoute(CLocation* pLocation) { this->pWestRoute = pLocation; }
  void SetListener(IEventNotifier* newListener);

	/* get functions, returns a pointer to location */
	inline CLocation* GetNorthRoute() { return this->pNorthRoute; }
	inline CLocation* GetEastRoute() { return this->pEastRoute; }
	inline CLocation* GetSouthRoute() { return this->pSouthRoute; }
	inline CLocation* GetWestRoute() { return this->pWestRoute; }
  inline IEventNotifier* GetListener() { return this->pListener; }

	void AddEvent(IEvent* pEvent);
	void ExecuteEvents();
	CLocation* AskRoute();

private:
	CLocation* pNorthRoute;
  CLocation* pEastRoute;
  CLocation* pSouthRoute;
  CLocation* pWestRoute;
  IEventNotifier* pListener;

	std::vector<IEvent*> Events;
};

#endif /* __CLOCATION_H__ */
