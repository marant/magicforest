#include "CBattleEvent.h"

#include <iostream>
#include "CGameCharacter.h"

CBattleEvent::CBattleEvent()
{
  this->Player   = NULL;
  this->Opponent = NULL;
}

CBattleEvent::CBattleEvent(CGameCharacter* pPlayer, CGameCharacter* pOpponent)
{
  this->Player = pPlayer;
  this->Opponent = pOpponent;
}

/*
 * do _NOT_ free the player as we'll be needing him even after the fight
 * we might also need the opponent for something (eg. looting) so we don't
 * delete anything in the destructor.
 */
CBattleEvent::~CBattleEvent()
{
}

bool CBattleEvent::SetPlayer( CGameCharacter* pPlayer )
{
  if( pPlayer )
  {
    this->Player = pPlayer;
    return true;
  }

  return false;
}

bool CBattleEvent::SetOpponent( CGameCharacter* pOpponent )
{
  if( pOpponent )
  {
    this->Opponent = pOpponent;
    return true;
  }

  return false;
}

/*
 * No idea why this function returns an integer, but we'll stick with 
 * it to avoid breaking anything :-D
 */
int CBattleEvent::RunEvent()
{

  // is the fight going on or not, yes the name sounds kinda stupid but gets
  // the message through
  bool FightIsOn = true; 

  // we can't really have a battle without anyone in it
  if( !Player || !Opponent )
  {
    return 0;
  }
  
  // Set targets so we can use the AttackTarget() function
  Player->SetTarget(Opponent);
  Opponent->SetTarget(Player);
  
  std::cout << "You're fighting against " << Opponent->GetName() << std::endl;

  while( FightIsOn )
  {
    int choice = 0;

    while( choice < 1 || choice > 3 )
    {
      std::cout << "Your opponent has " << Opponent->GetHP() << "HP left";
      std::cout << std::endl;
      std::cout << "You have " << Player->GetHP() << "HP left";
      std::cout << std::endl;
      std::cout << "What are you going to do?" << std::endl;
      std::cout << "1. Strike your foe down!" << std::endl;
      std::cout << "2. Run away like a little girl and cry yourself to sleep!";
      std::cout << std::endl;

      std::cout << "Your choice: ";
      std::cin >> choice;
    }

    if( choice == 1 )
    {
      std::cout << "YEAH!! You dealt " << Player->AttackTarget() << " damage to ";
      std::cout << Opponent->GetName() << std::endl; 

      std::cout << Opponent->GetName() << " Deals " << Opponent->AttackTarget();
      std::cout << " damage to you!" << std::endl;
    }

    // haven't really thought escaping through yet so we'll just insult the 
    // player.
    else if( choice == 2 )
    {
      std::cout << "YOU COWARD! Get back in the there!" << std::endl;
      std::cout << Opponent->GetName() << " Will get a free strike at you!";
      std::cout << std::endl;
      std::cout << Opponent->GetName() << " Deals " << Opponent->AttackTarget();
      std::cout << " damage to you!" << std::endl;
    }

    if( Opponent->GetHP() == 0 )
    {
      std::cout << "Congratulations! You killed " << Opponent->GetName();
      std::cout << std::endl;
      FightIsOn = false;
    }

    else if( Player->GetHP() == 0 )
    {
      std::cout << "You died :(" << std::endl;
      std::cout << "You weren't able to make it out of the magic forest";
      std::cout << std::endl;
      FightIsOn = false;
    }
  }

  return 0;
}
