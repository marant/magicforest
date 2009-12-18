#ifndef __IEVENT_H__
#define __IEVENT_H__

/*
 * Author: Marko "marant" Silokunnas
 * Date: 23.11.2009 
 * Description: 
 *
 * This abstract class defines an event. 
 *
 * All events have to implement the RunEvent function defined in this class.
 * The whole game consists of events that are linked together and executed 
 * in a previously set order (the order in which they are inserted into 
 * the event vector inside an Location for example).
 *
 * Events can also be "attached" to GameObjects(opening a chest for example)
 * or to Locations (fights, puzzles etc).
 *
 * Events can also have objects of their own as you might want to be able to
 * create an event in which you find something etc.
 *
 * This file also defines IEventNotifier, all classes that want to 
 * communicate with classes that extend IEvent have to implement
 * functions defined in IEventNotifier.
 *
 */

#include <vector>
#include <iostream>

class IGameObject;
class CLocation;
class CGameCharacter;

class IEventNotifier 
{

public:
  virtual void LocationChanged( const CLocation* pNewLocation ) = 0;
  virtual void PlayerDied( const CGameCharacter* pPlayer ) = 0;
};

class IEvent 
{

public:
  IEvent();
  virtual ~IEvent();

  /*
   * SetDescription returns a pointer to the string and it's sole purpose 
   * is to check that the set operation succeeded. 
   * DO NOT USE IT FOR ANYTHING ELSE
   */
  std::string* SetDescription(std::string newDescription);
  bool SetListener( IEventNotifier* newListener);

  inline IEventNotifier* GetListener() const { return this->Listener; }
  inline std::string GetDescription() { return this->Description; }

  IGameObject* AddObject( IGameObject* pNewObject );
  IGameObject* RemoveObject( int index );
  IGameObject* RemoveObject( IGameObject* pRemoveThisObject );

  virtual int RunEvent() = 0; 

protected:
  std::string Description;
  std::vector<IGameObject*> ObjectList;
  IEventNotifier* Listener;

};

#endif /* __IEVENT_H__ */
