#pragma once
#include "ElectricalDevices.h"
class Monitor :
	public ElectricalDevices
{
public:
	Monitor(double widthSh, double heightSh, string nameSh = "Монитор", double costSh = 350.43, TypeGood typeSh = COMPUTER) :
		ElectricalDevices(nameSh, costSh, typeSh), width(widthSh), height(heightSh) {}
	Monitor(const Monitor &obj) : ElectricalDevices(obj), width(obj.width), height(obj.height) {}

	void setWidth(double width);
	void setHeight(double height);
	double getWidth();
	double getHeight();

	~Monitor() {}

private:
	double width;
	double height;
};

