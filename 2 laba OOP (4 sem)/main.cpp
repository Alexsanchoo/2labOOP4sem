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
	
	Shop shop("Электро-экспресс");
	ClientData *clientData = nullptr;
	Order order;
		
	int choice = 0;
	while (choice != 4)
	{
		cout << "~~~~~" << shop.getName() << "~~~~" << endl;
		cout << "1. Добавить товар в ассортимент" << endl;
		cout << "2. Просмотреть ассортимент" << endl;
		cout << "3. Оформить заказ" << endl;
		cout << "4. Выход." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Сделайте выбор: ";
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
				cout << "Выберите, какой товар вы хотите добавить: " << endl;
				cout << "1. Монитор" << endl;
				cout << "2. Клавиатура" << endl;
				cout << "3. Холодильник" << endl;
				cout << "4. Утюг" << endl;
				cout << "5. Назад" << endl;
				cout << "Сделайте выбор: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch)
				{
				case 1:
					device = new Monitor();
					DepartmentManager::addGood(device, shop.getComputerDep());
					cout << "Монитор успешно добавлен в ассортимент!" << endl << endl;
					break;

				case 2:
					device = new Keyboard();
					DepartmentManager::addGood(device, shop.getComputerDep());
					cout << "Клавиатура успешно добавлена в ассортимент!" << endl << endl;
					break;

				case 3:
					device = new Fridge();
					DepartmentManager::addGood(device, shop.getHouseholdDep());
					cout << "Холодильник успешно добавлен в ассортимент!" << endl << endl;
					break;

				case 4:
					device = new Iron();
					DepartmentManager::addGood(device, shop.getHouseholdDep());
					cout << "Утюг успешно добавлен в ассортимент!" << endl << endl;
					break;

				case 5:
					system("cls");
					break;

				default:
					cout << "Неверный выбор!" << endl << endl;
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
				cout << "Нет товара!" << endl;
			}
			cout << endl;
			if (!DepartmentManager::showGoods(shop.getHouseholdDep()))
			{
				cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
				cout << "Нет товара!" << endl;
			}
			system("pause>>void");
			system("cls");
			break;

		case 3:
		{
			int ch = 0;
			while (ch != 5)
			{
				cout << "Оформление заказа: " << endl;
				cout << "1. Заполнение личных данных клиента" << endl;
				cout << "2. Выбрать товар из компьютерного отдела" << endl;
				cout << "3. Выбрать товар из бытового отдела" << endl;
				cout << "4. Завершить заказ" << endl;
				cout << "5. Назад" << endl;
				cout << "Сделайте выбор: ";
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
						cout << "Данные о клиенте уже заполнены!" << endl << endl;
					}
					break;

				case 2:
				{
					int ch = 0;
					ElectricalDevices *device = nullptr;
					DepartmentManager::showGoods(shop.getComputerDep());
					cout << endl << "Выберите номер товара: ";
					while (ch < 1 || ch > shop.getComputerDep().getGoods().size())		//ДОБАВИТЬ СЮДА ИСКЛЮЧЕНИЕ
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
					cout << endl << "Выберите номер товара: ";
					while (ch < 1 || ch > shop.getHouseholdDep().getGoods().size())		//ДОБАВИТЬ СЮДА ИСКЛЮЧЕНИЕ
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
						cout << "Общая сумма: " << order.getTotalSum() << "$" << endl;
						system("pause>>void");
						system("cls");
					}
					else
					{
						cout << "Список товаров пуст или данные о клиенте ещё не заполнены!" << endl << endl;
					}
				}
					break;

				case 5:
					break;

				default:
					cout << "Неверный выбор!" << endl << endl;
					break;
				}
			}
		}
			system("cls");
			break;

		case 4:
			break;

		default:
			cout << "Неверный выбор!" << endl << endl;
			break;
		}
	}

	delete clientData;
	return 0;
}