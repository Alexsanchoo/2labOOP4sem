#pragma once
#include "ElectricalDevices.h"
class Iron :
	public ElectricalDevices
{
public:
	Iron(double maxTemp, string nameSh = "����", double costSh = 120.0, TypeGood typeSh = HOUSEHOLD) :
	ElectricalDevices(nameSh, costSh, typeSh), maxTemperature(maxTemp) {}
	Iron(const Iron &obj) : ElectricalDevices(obj), maxTemperature(obj.maxTemperature) {}

	void setMaxTemp(double temp);
	double getMaxTemp();

	~Iron() {}

private:
	double maxTemperature;
};

