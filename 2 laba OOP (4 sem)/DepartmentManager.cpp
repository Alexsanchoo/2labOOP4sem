#include "DepartmentManager.h"

void DepartmentManager::addGood(ElectricalDevices * good, Department & obj)
{
	obj.getGoods().push_back(good);
}

int DepartmentManager::showGoods(Department & obj)
{
	if (!obj.getGoods().size())
	{
		return 0;
	}

	cout << "~~~" << obj.getName() << "~~~" << endl;
	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		cout << i + 1 << ". " << obj.getGoods()[i]->getName() << endl;
	}
	return 1;
}

ElectricalDevices * DepartmentManager::removeGood(int index, Department & obj)
{
	ElectricalDevices* temp = obj.getGoods()[index];
	obj.getGoods().erase(obj.getGoods().begin() + index);
	return temp;
}
