#pragma once
#include<string>
#include<vector>
#include "ElectricalDevices.h"

using namespace std;

class Department
{
public:
	Department(string nameSh = "") : name(nameSh) {}
	Department(const Department &obj);

	void setName(string name);
	string getName();

	~Department() {}

private:
	string name;
	vector<ElectricalDevices*> goods;
};

