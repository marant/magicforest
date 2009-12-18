#include "IEvent.h"

#include "IGameObject.h"


// Constructor, nothing interesting here
IEvent::IEvent( )
{
  this->Description = "Not set";
  this->Listener    = NULL;
}

// Destructor frees the ObjectList and that's pretty much it
IEvent::~IEvent()
{
  int i=0;
  for (i = 0; i < ObjectList.size(); i++) 
  {
    delete ObjectList[i];
    ObjectList[i] = NULL;
  }

  ObjectList.clear();
}

/* NOTE! The return value is a pointer! */
std::string* IEvent::SetDescription( std::string newDescription )
{
  this->Description = newDescription;
  return &Description;
}

bool IEvent::SetListener(IEventNotifier* newListener)
{
  if( !newListener )
  {
    return false;
  }

  this->Listener = newListener;
  return true;
}

IGameObject* IEvent::AddObject( IGameObject* pNewObject )
{
  if (pNewObject) 
  {
    ObjectList.push_back( pNewObject );
    return pNewObject;
  }

  return NULL;
}


/*
 * Removes object that is specified in the parameter from the object list,  if
 * it is found. Returns a pointer to the removed object and is meant to be
 * used when the player acquires something from an event (finds something for
 * example).
 *
 * 
 */
IGameObject* IEvent::RemoveObject( int index )
{
  /* doesn't std::vector provide a cleaner way of doing this? All I found was
   * a pop_back() function which really isn't what I'm looking for...
   */
  IGameObject* tmp = NULL;
  tmp = ObjectList.at( index );
  
  if (tmp) 
  {
    ObjectList.erase( ObjectList.begin()+index );
    return tmp;
  }

  return NULL;
}

IGameObject* IEvent::RemoveObject( IGameObject* pRemoveThisObject )
{
  /*
   * iterates through the vector and compares the given pointer to all elements
   * in the vector. Kinda ugly I know.
   */
  
  //TODO: find a cleaner way to do this!

  if( !pRemoveThisObject )
  {
    return NULL;
  }

  int i=0;
  for (i = 0; i < ObjectList.size(); i++) 
  {
    if (ObjectList[i] == pRemoveThisObject ) 
    {
      IGameObject* tmp = this->RemoveObject(i);
      if (tmp) 
      {
        return tmp;
      }
    }
  }

  return NULL;
}
