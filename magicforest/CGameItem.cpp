#include "CGameItem.h"

CGameItem::CGameItem()
{
  this->pOwner = NULL;
}

CGameItem::CGameItem( CGameCharacter* pNewOwner )
{
  this->pOwner = pNewOwner;
}

CGameItem::~CGameItem()
{
  if( pOwner )
  {
    delete this->pOwner;
    this->pOwner = NULL;
  }
}

bool CGameItem::SetOwner( CGameCharacter* pNewOwner )
{
  if ( pNewOwner ) 
  {
    this->pOwner = pNewOwner;
    return true;
  }

  return false;
}

