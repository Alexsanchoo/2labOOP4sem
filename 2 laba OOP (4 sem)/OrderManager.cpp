#include "OrderManager.h"

void OrderManager::addGood(ElectricalDevices * good, Order & obj)
{
	obj.getGoods().push_back(good);
	obj.setTotalSum(obj.getTotalSum() + good->getCost());
}

int OrderManager::showGoods(Order & obj)
{
	if (!obj.getGoods().size())
	{
		return 0;
	}

	cout << "~~~ÇÀÊÀÇ~~~" << endl;
	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		cout << i + 1 << ". " << obj.getGoods()[i]->getName() << endl;
	}
	return 1;
}
