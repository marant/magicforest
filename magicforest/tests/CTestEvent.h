#ifndef __CTESTEVENT_H__
#define __CTESTEVENT_H__

#include "../IEvent.h"
#include "../CLocation.h"

#include <iostream>

class CTestEvent : public IEvent {
public:
  CTestEvent();
  ~CTestEvent();

  int RunEvent();
};

#endif /* __CTESTEVENT_H__ */
