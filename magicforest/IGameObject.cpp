#include "IGameObject.h"

#include "IEvent.h"
#include "CLocation.h"
/*
 * SETTERS
 */

IGameObject::IGameObject( )
{
  this->Location = NULL; 
  this->AssociatedEvent = NULL;
  this->Description = "Not set";
  this->Name = "Not set";
}
/*
 * Sets new location and returns a pointer to the new location.
 * Note that you should NOT use the returned pointer in anything, aside
 * from checking whether or not the set was successfull.
 *
 * All setter functions work like this.
 */
CLocation* IGameObject::SetLocation( CLocation* pNewLocation )
{
  if( pNewLocation )
  {
    this->Location = pNewLocation;
    return this->Location;
  }

  else {
    return NULL;
  }
}

std::string IGameObject::SetDescription( std::string Description )
{
  this->Description = Description;
  return this->Description;
}

std::string IGameObject::SetName( std::string newName )
{
  this->Name = newName;
  return this->Name;
}

IEvent* IGameObject::SetAssociatedEvent( IEvent* pNewAssociatedEvent )
{
  if( pNewAssociatedEvent )
  {
    this->AssociatedEvent = pNewAssociatedEvent;
    return this->AssociatedEvent;
  }

  else 
  {
    return NULL;
  }
}
