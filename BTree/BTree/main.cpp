#include <iostream>
#include <ostream>
#include <sstream>
#include <list>

#include "TasksDoor.h"
#include "CParseLevel.h"

int selection = 0;
bool isRunning = true;

bool foodSet = false;
bool danger = false;

gen::CParseXML parseFile;

Node* root = new Sequence();

gen::CParseLevel levelParser(root);

// Behaviour tree that models the behaviour of a person whose goal is to open a door.
void DoorExample()
{
	/*
	////Create nodes
	//Sequence *root = new Sequence, *sequence1 = new Sequence, *sequence2 = new Sequence;;  // Note that root can be either a Sequence or a Selector, since it has only one child.
	//Selector *selector1 = new Selector, *selector2 = new Selector;  // In general there will be several nodes that are Sequence or Selector, so they should be suffixed by an integer to distinguish between them.
	//
	////Set door status


	//
	////Inititalise tasks
	////CheckIfDoorIsOpenTask* checkOpen = new CheckIfDoorIsOpenTask(doorStatus);
	////ApproachDoorTask* approach = new ApproachDoorTask(doorStatus, false);
	////OpenDoorTask* open = new OpenDoorTask(doorStatus);
	////UnlockDoorTask* unlock = new UnlockDoorTask(doorStatus);
	////SmashDoorTask* smash = new SmashDoorTask(doorStatus);
	////EnterDoorTask* enter = new EnterDoorTask(doorStatus);

	////Root
	//root->addChild(sequence1);

	////Depth 1
	//sequence1->addChild(approach);
	//sequence1->addChild(selector1);
	//sequence1->addChild(enter);

	////Depth 2
	//selector1->addChild(open);
	//selector1->addChild(sequence2);
	//selector1->addChild(smash);

	////Depth 3
	//sequence2->addChild(unlock);
	//sequence2->addChild(open);
	*/
	// If the operation starting from the root fails, keep trying until it succeeds.
	while (!root->run())
	{
		std::cout << "--------------------" << std::endl;
	}
	std::cout << std::endl << "Operation complete.  Behaviour tree exited." << std::endl;
}



void main() 
{
	//while (isRunning)
	//{
	//	std::cout << std::endl;
	//	std::cout << "-----------------------------" << std::endl;
	//	std::cout << "Select a simulation:" << std::endl;
	//	std::cout << "1 = Open Door" << std::endl;
	//	//std::cout << "2 = Prey searching for food" << std::endl;
	//	std::cout << "3 = Quit" << std::endl;
	//	std::cin >> selection;
	//	std::cout << std::endl << std::endl;

	//	switch (selection)
	//	{
	//		
	//	default:
	//		break;
	//	case 0:
	//		break;
	//	case 1:
	//		std::system("CLS");
	//		DoorExample();		
	//		break;
	//	case 2:
	//		std::system("CLS");
	//		/*PreyExample();*/
	//		break;
	//	case 3:
	//		isRunning = false;
	//		break;
	//	}
	//	std::cout << "-----------------------------" << std::endl;
	//}

	levelParser.ParseFile("Entities.xml");

	while (!root->run())
	{
		std::cout << "--------------------" << std::endl;
	}
	std::cout << std::endl << "Operation complete.  Behaviour tree exited." << std::endl;


	std::system("PAUSE");

}
