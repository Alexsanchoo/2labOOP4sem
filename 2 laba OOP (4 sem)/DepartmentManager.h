#pragma once
#include<iostream>
#include "ElectricalDevices.h"
#include"Department.h"

using namespace std;

class DepartmentManager
{
public:
	static void addGood(ElectricalDevices *good, Department &obj);
	static int showGoods(Department &obj);
};

