#ifndef __CENDEVENT_H__
#define __CENDEVENT_H__

/*
 * Author: Marko Silokunnas
 * Date: 18.12.2009 
 * Description: 
 *
 * This class defines an event which calls it's listener to end the game.
 *
 */

#include "IEvent.h"

class CEndEvent : public IEvent{
public:
  CEndEvent();
  ~CEndEvent();

  int RunEvent(); 
};

#endif /* __CENDEVENT_H__ */
