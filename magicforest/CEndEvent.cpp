#include "CEndEvent.h"
#include <iostream>

CEndEvent::CEndEvent()
{
}

CEndEvent::~CEndEvent()
{
}

int CEndEvent::RunEvent()
{
  if( Listener )
  {
    Listener->GameEnded();
  }
}
