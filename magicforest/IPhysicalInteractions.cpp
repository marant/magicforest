#include "IPhysicalInteractions.h"
#include "CGameCharacter.h"

IPhysicalInteractions::IPhysicalInteractions( )
{
  this->pTarget = NULL;
  this->AttackModifier = 0;
  this->HP = 0;
}

/*
 * Decreases HP by the given amount and returns the amount of HP
 * decreased which can differ from the given value due to 
 * armors or something. Altough at this point it is unkown
 * whether or not armour effect should be handled above this
 * class, but atleast we'll be prepared to do it in this class.
 * (It would still require some changes, but I think we could manage it
 * without affecting the public interface...)
 * 
 * Note returns a POSITIVE value for the decrease!
 */
float IPhysicalInteractions::DecreaseHP( float HPDecrease )
{
  return (-1)*this->ChangeHP( HPDecrease*(-1) );
}

/*
 * Does the opposite of DecreaseHP
 */
float IPhysicalInteractions::IncreaseHP( float HPIncrease )
{
  return this->ChangeHP(HPIncrease);
}

/*
 * Increases or decreases HP. If change > 0 HP is increased
 * and if change < 0 HP is decreased.
 * Used Internally in Increase- and DecreaseHP to minimize 
 * code duplication
 */
float IPhysicalInteractions::ChangeHP( float change )
{
  float newHP = this->HP + change;
  if( newHP >= 0 )
  {
    this->HP = newHP;
    return change;
  }

  else 
  {
    this->HP = 0;
    return 0;
  }

  return 0;
}

bool IPhysicalInteractions::SetTarget( CGameCharacter* newTarget )
{
  if( !newTarget )
    return false;

  this->pTarget = newTarget;
  return true;
}

bool IPhysicalInteractions::SetHP( float newHP )
{
  this->HP = newHP;
  return true;
}

bool IPhysicalInteractions::SetAttackModifier( float newAttackModifier )
{
  this->AttackModifier = newAttackModifier;
  return true;
}


/*
 * attacks the target by reducing target's HP
 * returns the amount of damage dealt
 */
float IPhysicalInteractions::AttackTarget()
{
  if( !pTarget )
  {
    return 0;
  }

  return pTarget->DecreaseHP(AttackModifier);
}
