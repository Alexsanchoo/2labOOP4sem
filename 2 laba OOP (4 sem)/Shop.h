#pragma once
#include<string>
#include "Department.h"

using namespace std;

class Shop
{
public:
	Shop(string nameSh = "") : name(nameSh) {}

	void setName(string name);
	string getName();

	~Shop() {}

private:
	string name;
	Department household;
	Department computer;
};

