#include "IInteractionEssentials.h"

IInteractionEssentials::IInteractionEssentials()
{
	/* constructor */
}

IInteractionEssentials::~IInteractionEssentials()
{
	/* destructor */
}

/*
 * Adds a choice to the Choices vector
 * PROTIP: a Choice shall contain an integer to indicate
 * the order of the choices; a player will type this 
 * number when asked to choose an action.
 */
void IInteractionEssentials::AddChoice(std::string newchoice)
{
	Choices.push_back(newchoice);
}

void IInteractionEssentials::ShowText()
{
	printf("%s\n", TextToPrint.c_str());
}

/*
 * Returns an integer, indicated in the
 * choice.
 */
int IInteractionEssentials::AskChoice()
{
	int i, playerchoice;

	this->ShowText();

	for (i = 0; i < Choices.size(); i++)
	{
		printf("%s\n",Choices[i].c_str());
	}

	printf("Choose an action: ");
	scanf("%d",&playerchoice);

	return playerchoice;

}
