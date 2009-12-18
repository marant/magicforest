/**
 * Author: Juhani "argontus" Alanko
 * Date: 2009-12-13
 * Description: 
 * 
 * The game class that orchestrates the location changing 
 * and moves the character.
 * 
 */

#ifndef __CGAME_H__
#define __CGAME_H__

#include <vector>
#include <iostream>

#include "IEvent.h"
#include "CGameCharacter.h"

class CGame : public IEventNotifier 
{
public:
	CGame ();
  ~CGame();

	void Start();
	void End();
  void AskPlayerInfo();

private:
	CGameCharacter* Player;
	std::vector<CLocation*> Locations;
  CLocation* CurrentLocation;
  void LocationChanged( CLocation* newLocation );
  void PlayerDied( CGameCharacter* Player );
  void GameEnded();
};

#endif /* __CGAME_H__ */
