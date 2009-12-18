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

  float DecreaseHP( float amount );
  float IncreaseHP( float amount );


  float AttackTarget();

  /* set */
  bool SetTarget( CGameCharacter* newTarget );
  bool SetAttackModifier( float newAttackModifier );
  bool SetHP( float newHP );
  
  /* get */
  CGameCharacter* GetTarget() const { return this->pTarget; }
  inline float GetHP() const { return this->HP; }

private:
  CGameCharacter* pTarget;
  float HP;
  float AttackModifier; // used to reduce enemy HP

  /*
   * Increases or decreases HP. If change > 0 HP is increased
   * and if change < 0 HP is decreased.
   * Used Internally in Increase- and DecreaseHP to minimize 
   * code duplication
   */
   float ChangeHP( float change );
};

#endif /* __IPHYSICALINTERACTIONS_H__ */
