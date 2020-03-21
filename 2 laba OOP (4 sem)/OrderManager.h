#pragma once
#include<iostream>
#include "ElectricalDevices.h"
#include "Order.h"

using namespace std;

class OrderManager
{
public:
	static void addGood(ElectricalDevices* good, Order &obj);
	static int showGoods(Order &obj);
};

