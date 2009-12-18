#ifndef __CBATTLEEVENT_H__
#define __CBATTLEEVENT_H__

/*
 * Author: Marko Silokunnas
 * Date: 18.12.2009 
 * Description: 
 *
 * Extends IEvent and implements a battle event in which two CGameCharacters
 * engage in a fight. One of the CGameCharacters engaged in the fight is always
 * the player. 
 *
 */
 
class CBattleEvent : IEvent {
public:
  CBattleEvent();
  CBattleEvent(CGameCharacter* pPlayer, CGameCharacter* pOpponent);
  ~CBattleEvent();

  /* 
   * declared in IEvent as virtual so we have to implement it
   * this function is called when the battle begins and returns when the
   * battle ends.
   */
  int RunEvent();

  bool SetPlayer( CGameCharacter* pPlayer);
  bool SetOpponent( CGameCharacter* pOpponent);

  inline CGameCharacter* GetOpponent() const { return this->Opponent; }
  inline CGameCharacter* GetPlayer() const { return this->Player; }

private:
  CGameCharacter* Player;
  CGameCharacter* Opponent;
};

#endif /* __CBATTLEEVENT_H__ */
