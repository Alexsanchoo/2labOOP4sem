#include "Order.h"

void Order::setData(ClientData * data)
{
	this->data = data;
}

void Order::setTotalSum(double sum)
{
	totalSum = sum;
}

ClientData * Order::getData()
{
	return data;
}

double Order::getTotalSum()
{
	return totalSum;
}
