#pragma once
#include <ctime>

#include "nodes.h"

enum Weather { fine, cold, warm };

bool isAlive = true;
int daysHungry = 0;

struct Climate {
	int days;
	bool disaster;
	Weather temperature;
};

struct Area {
	int richness;
	bool richInFood;
	bool safe;
	bool hasHidingSpots;
};

class CheckForFood : public Node
{  // Each task will be a class derived from Node
private:
	Area * status;
public:
	CheckForFood(Area* status) : status(status) {}
	virtual bool run() override
	{
		if (status->richness > 0)
			status->richInFood = true;
		else
			status->richInFood = false;

		if (status->richInFood)
		{
			std::cout << "Area is rich enough in food to stay" << std::endl;
			return true;
		}
		else
		{
			std::cout << "No food, Searching..." << std::endl;
			daysHungry++;
			std::cout << "Days hungry: " << daysHungry << std::endl;
			return false;
		}


	}
};

class FindFood : public Node
{  // Each task will be a class derived from Node
private:
	Area * status;
public:
	FindFood(Area* status) : status(status) {}
	virtual bool run() override
	{
		std::cout << "Travelling..." << std::endl;

		if (status->richInFood)
		{
			std::cout << "Area is rich enough in food to stay";  // will return true
			if (status->safe)
			{
				std::cout << " and area is safe" << std::endl;
				return true;
			}
			else
			{
				std::cout << " but area is not safe" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "No food, Searching..." << std::endl;  // will return false
			return false;
		}
	}
};

class ConsumeFood : public Node
{  // Each task will be a class derived from Node
private:
	Area * status;
public:
	ConsumeFood(Area* status) : status(status) {}
	virtual bool run() override
	{
		if (status->safe)
		{
			std::cout << "Consuming food" << std::endl;
			status->richness--;
			daysHungry = 0;
			std::cout << "Food amount: " << status->richness << std::endl;
			return true;
		}
		else
		{
			std::cout << "Danger afoot, moving..." << std::endl;
			return false;
		}
	}
};