
#include "CTestEvent.h"

CTestEvent::CTestEvent()
 : IEvent()
{
  //calls IEvent destructor
}


CTestEvent::~CTestEvent()
{
  /*// deletes everything from the ObjectList
  int i=0;
  for( i=0; i < ObjectList.size(); i++ )
  {
    delete ObjectList[i];
    ObjectList[i] = NULL;
  }*/
}

int CTestEvent::RunEvent()
{
  std::cout << this->GetDescription() << std::endl; 
  return 0;
}
