#ifndef __CPLAYER_H__
#define __CPLAYER_H__

/*
 * Author: Marko "marant" Silokunnas
 * Date: 13.12.2009 
 * Description: 
 *
 * This class defines a player class that holds data related to a player,
 * such as his/her name and how many monsters he/she has killed etc.
 *
 * Even though the current implementation is extremely simple, other features
 * could(and should) be added in the future.
 *
 */
 
#include <iostream>

class CPlayer {
public:
  CPlayer ();

  void SetName( std::string newName );
  inline std::string GetName() const { return this->Name; }

private:
  std::string Name;
};

#endif /* __CPLAYER_H__ */
