#ifndef __IPHYSICALINTERACTIONS_H__
#define __IPHYSICALINTERACTIONS_H__

/**
 * Author: Marko Silokunnas 
 * Date: 2009-12-02
 * Description:
 *
 * An abstract class that enables game characters and objects to interact
 * with the player. 
 */

#include <iostream>

class CGameCharacter;

class IPhysicalInteractions 
{
public:
  IPhysicalInteractions();
  virtual ~IPhysicalInteractions() = 0;

  float DecreaseHP( float amount );
  float IncreaseHP( float amount );

  /* set */
  bool SetTarget( CGameCharacter* newTarget );
  
  /* get */
  CGameCharacter* GetTarget() const { return this->pTarget; }

private:
  CGameCharacter* pTarget;
  float HP;
  float AttackModifier;

  /*
   * Increases or decreases HP. If change > 0 HP is increased
   * and if change < 0 HP is decreased.
   * Used Internally in Increase- and DecreaseHP to minimize 
   * code duplication
   */
   float ChangeHP( float change );
};

#endif /* __IPHYSICALINTERACTIONS_H__ */
