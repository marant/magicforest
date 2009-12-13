#ifndef __CGAMECHARACTER_H__
#define __CGAMECHARACTER_H__

/**
 * Author: Juhani "argontus" Alanko
 * Date: 2009-12-13
 * Description: 
 * 
 * A character class that is essentially a container for 
 * inventory. This is used for the player and NPCs alike.
 * 
 */

#include <vector>
#include <iostream>


class CGameCharacter : public IGameObject, 
											 public IPhysicalInteractions, 
											 public	IInteractionEssentials
{
public:
	CGameCharacter ();
	CGameCharacter (std::string name);
	virtual ~CGameCharacter ();

	CGameItem* AddToInventory(CGameItem* pItem);
	CGameItem* RemoveItemFromInventory(CGameItem* pItem);
private:
	std::vector<CGameItem*> Inventory;
};

#endif /* __CGAMECHARACTER_H__ */
