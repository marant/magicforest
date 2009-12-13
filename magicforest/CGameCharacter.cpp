#include "CGameCharacter.h"

CGameCharacter::CGameCharacter()
{
	/* constructor */
}

CGameCharacter::CGameCharacter (std::string name)
{
	this->SetName(name);
}

CGameCharacter::~CGameCharacter()
{
	/* delete all items in inventory */
	unsigned int i;
	for (i = 0; i < Inventory.size(); i++)
	{
		CGameItem* tempItem = NULL;
		tempItem = Inventory[i];
		delete tempItem;
	}
	Inventory.clear();
}

CGameItem* CGameCharacter::AddToInventory(CGameItem* pItem)
{
	this->Inventory.push_back(pItem);

	return pItem;
}

CGameItem* CGameCharacter::RemoveItemFromInventory(CGameItem* pItem)
{
	unsigned int i;
	for (i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i] == pItem) 
		{
			CGameItem* tempItem = NULL;
			tempItem = Inventory[i];
			delete tempItem;
		}
	}

	return pItem;
}
