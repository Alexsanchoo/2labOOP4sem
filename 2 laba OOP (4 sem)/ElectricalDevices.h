#pragma once
#include<string>

using namespace std;

enum TypeGood {
	NONE,
	HOUSEHOLD,
	COMPUTER
};

class ElectricalDevices
{
public:
	ElectricalDevices(string nameSh = "", double costSh = 0.0, TypeGood typeSh = NONE, int countSh = 0) : 
		name(nameSh), cost(costSh), type(typeSh), count(0) {}
	ElectricalDevices(const ElectricalDevices &obj) : name(obj.name), cost(obj.cost), type(obj.type), count(obj.count) {}

	void setName(string name);
	void setCost(double cost);
	void setType(TypeGood type);
	void setCount(int count);
	string getName();
	double getCost();
	TypeGood getType();
	int getCount();

	virtual ~ElectricalDevices() {}

protected:
	string name;
	double cost;
	TypeGood type;
	int count;
};

