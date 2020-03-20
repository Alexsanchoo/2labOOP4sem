#include "ElectricalDevices.h"

void ElectricalDevices::setName(string name)
{
	this->name = name;
}

void ElectricalDevices::setCost(double cost)
{
	this->cost = cost;
}

void ElectricalDevices::setType(TypeGood type)
{
	this->type = type;
}

void ElectricalDevices::setCount(int count)
{
	this->count = count;
}

string ElectricalDevices::getName()
{
	return name;
}

double ElectricalDevices::getCost()
{
	return cost;
}

TypeGood ElectricalDevices::getType()
{
	return type;
}

int ElectricalDevices::getCount()
{
	return count;
}
