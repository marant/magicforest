#ifndef __IGAMEOBJECT_H__
#define IGAMEOBJECT

/*
 * Author: Marko "marant" Silokunnas
 * Date: 23.11.2009 
 * Description: 
 *
 * This abstract class defines functions and attributes that
 * every single object in the game world has to have. Eg, location, name
 * and description. _ALL_ game objects implement this abstract class.
 * 
 */
 
#include <iostream>

#include "CEvent.h"
#include "CLocation.h"

class IGameObject {
public:
  virtual ~IGameObject() = 0;

  /* SETTERS 
   *
   * All setters return a pointer to a  class/struct/whatever they're supposed
   * to set. The return value is used to check whether or not the set was
   * successful or not. 
   *
   * NOTE!
   * do not use the return value for anything else than checking, because
   * by the time you want to use it, it might have already been deleted!
   */
  CLocation* SetLocation(CLocation* pNewLocation);
  CEvent *SetAssociatedEvent(CEvent* pNewEvent);
  std::string SetDescription(std::string Description);
  std::string SetName(std::string Name);

  /* GETTERS 
   *
   * Not really that difficult to grasp
   * */
  inline CLocation* GetLocation() { return this->Location; }
  inline CEvent*  GetAssociatedEvent() { return this->AssociatedEvent; }
  inline std::string GetDescription() { return this->Description; }
  inline std::string GetName() { return this->Name; }
  
private:
  CLocation* Location;
  CEvent* AssociatedEvent;
  std::string Description;
  std::string Name;
};

#endif /* __IGAMEOBJECT_H__ */
