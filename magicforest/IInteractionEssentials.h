#ifndef __IINTERACTIONESSENTIALS_H__
#define __IINTERACTIONESSENTIALS_H__
	
/*
 * Author: Juhani Alanko
 * Date: 2009-11-30
 * Description: 
 *
 * An abstract class that every interactive class shall
 * implement. Contains printable text, a vector of choices 
 * and a method to show the text and ask the player some 
 * choices related to the text.
 *
 */


#include <iostream>
#include <vector>
#include <stdio.h>

class IInteractionEssentials 
{
public:
	IInteractionEssentials();
	~IInteractionEssentials();

	void AddChoice(std::string newchoice);

	int AskChoice();

private:
	void ShowText();

	std::string TextToPrint;
	std::vector<std::string> Choices;
};

#endif /* __IINTERACTIONESSENTIALS_H__ */
