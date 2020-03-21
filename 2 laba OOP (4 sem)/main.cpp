#include<iostream>
#include<Windows.h>
#include "ValidValue.h"
#include "Shop.h"
#include "ClientData.h"
#include "Order.h"
#include "Fridge.h"
#include "Iron.h"
#include "Monitor.h"
#include "Keyboard.h"
#include "DepartmentManager.h"
#include "OrderManager.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);
	
	Shop shop("�������-��������");
	ClientData *clientData = nullptr;
	Order order;
		
	int choice = 0;
	while (choice != 4)
	{
		cout << "~~~~~" << shop.getName() << "~~~~" << endl;
		cout << "1. �������� ����� � �����������" << endl;
		cout << "2. ����������� �����������" << endl;
		cout << "3. �������� �����" << endl;
		cout << "4. �����." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "�������� �����: ";
		choice = ValidValue<>::getValue();

		system("cls");
		switch (choice)
		{
		case 1:
		{
			ElectricalDevices* device = nullptr;
			int ch = 0;
			while (ch != 5)
			{
				cout << "��������, ����� ����� �� ������ ��������: " << endl;
				cout << "1. �������" << endl;
				cout << "2. ����������" << endl;
				cout << "3. �����������" << endl;
				cout << "4. ����" << endl;
				cout << "5. �����" << endl;
				cout << "�������� �����: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch)
				{
				case 1:
					device = new Monitor();
					DepartmentManager::addGood(device, shop.getComputerDep());
					cout << "������� ������� �������� � �����������!" << endl << endl;
					break;

				case 2:
					device = new Keyboard();
					DepartmentManager::addGood(device, shop.getComputerDep());
					cout << "���������� ������� ��������� � �����������!" << endl << endl;
					break;

				case 3:
					device = new Fridge();
					DepartmentManager::addGood(device, shop.getHouseholdDep());
					cout << "����������� ������� �������� � �����������!" << endl << endl;
					break;

				case 4:
					device = new Iron();
					DepartmentManager::addGood(device, shop.getHouseholdDep());
					cout << "���� ������� �������� � �����������!" << endl << endl;
					break;

				case 5:
					system("cls");
					break;

				default:
					cout << "�������� �����!" << endl << endl;
					break;
				}
			}
		}
			system("cls");
			break;

		case 2:
			if (!DepartmentManager::showGoods(shop.getComputerDep()))
			{
				cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
			}
			cout << endl;
			if (!DepartmentManager::showGoods(shop.getHouseholdDep()))
			{
				cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
			}
			system("pause>>void");
			system("cls");
			break;

		case 3:
		{
			int ch = 0;
			while (ch != 5)
			{
				cout << "���������� ������: " << endl;
				cout << "1. ���������� ������ ������ �������" << endl;
				cout << "2. ������� ����� �� ������������� ������" << endl;
				cout << "3. ������� ����� �� �������� ������" << endl;
				cout << "4. ��������� �����" << endl;
				cout << "5. �����" << endl;
				cout << "�������� �����: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch)
				{
				case 1:
					if (clientData == nullptr)
					{
						clientData = new ClientData();
						clientData->set();
						order.setData(clientData);
						system("cls");
					}
					else
					{
						cout << "������ � ������� ��� ���������!" << endl << endl;
					}
					break;

				case 2:
				{
					int ch = 0;
					ElectricalDevices *device = nullptr;
					DepartmentManager::showGoods(shop.getComputerDep());
					cout << endl << "�������� ����� ������: ";
					while (ch < 1 || ch > shop.getComputerDep().getGoods().size())		//�������� ���� ����������
					{
					ch = ValidValue<>::getValue();
					}
					device = DepartmentManager::removeGood(ch - 1, shop.getComputerDep());
					OrderManager::addGood(device, order);
				}
					system("cls");
					break;

				case 3:
				{
					int ch = 0;
					ElectricalDevices* device = nullptr;
					DepartmentManager::showGoods(shop.getHouseholdDep());
					cout << endl << "�������� ����� ������: ";
					while (ch < 1 || ch > shop.getHouseholdDep().getGoods().size())		//�������� ���� ����������
					{
						ch = ValidValue<>::getValue();
					}
					device = DepartmentManager::removeGood(ch - 1, shop.getHouseholdDep());
					OrderManager::addGood(device, order);
				}
					system("cls");
					break;

				case 4:
				{
					if (OrderManager::showGoods(order) && clientData != nullptr)
					{
						cout << endl;
						cout << "����� �����: " << order.getTotalSum() << "$" << endl;
						system("pause>>void");
						system("cls");
					}
					else
					{
						cout << "������ ������� ���� ��� ������ � ������� ��� �� ���������!" << endl << endl;
					}
				}
					break;

				case 5:
					break;

				default:
					cout << "�������� �����!" << endl << endl;
					break;
				}
			}
		}
			system("cls");
			break;

		case 4:
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}

	delete clientData;
	return 0;
}