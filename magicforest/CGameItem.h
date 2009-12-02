#ifndef __CGAMEITEM_H__
#define __CGAMEITEM_H__

/**
 * Author: Marko Silokunnas 
 * Date: 2009-12-02
 * Description: 
 *
 * Defines a game item class. Items only have an owner associated with them.
 * This class acts as a base class for other game items, such as swords 
 * potions etc.
 * 
 * Function names in this class speak for themselves. Everything is 
 * pretty damn simple.
 *
 */


#include "IGameObject.h"
class CGameCharacter;

class CGameItem : public IGameObject
{
public:
  CGameItem ();
  CGameItem( CGameCharacter* pNewOwner );
  ~CGameItem ();

  /* set */
  bool SetOwner( CGameCharacter* pNewOwner);

  /* get */
  CGameCharacter* GetOwner() const { return this->pOwner; }

private:
  CGameCharacter* pOwner;

};
#endif /* __CGAMEITEM_H__ */
