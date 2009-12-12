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

class CGame : public IEventNotifier 
{
public:
	CGame ();
	virtual ~CGame ();

	void Start();
	void End();

private:
	CGameCharacter Player;
	std::vector<CLocation*> Locations;
};

#endif /* __CGAME_H__ */
