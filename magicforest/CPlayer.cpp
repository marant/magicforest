#include "CPlayer.h"

CPlayer::CPlayer()
{
  this->Name = "Unkown";
}

void CPlayer::SetName( std::string newName)
{
  this->Name = newName;
}

