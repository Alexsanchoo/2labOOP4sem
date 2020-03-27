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
#include "ExpShop.h"

using namespace std;

void term_func();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);
	set_terminate(term_func);

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
			while (ch != 7)
			{
				cout << "Оформление заказа: " << endl;
				cout << "1. Заполнение личных данных клиента" << endl;
				cout << "2. Выбрать товар из компьютерного отдела" << endl;
				cout << "3. Выбрать товар из бытового отдела" << endl;
				cout << "4. Просмотреть выбранные товары" << endl;
				cout << "5. Убрать товар из заказа" << endl;
				cout << "6. Завершить заказ" << endl;
				cout << "7. Назад" << endl;
				cout << "Сделайте выбор: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch)
				{
				case 1:
					if (clientData == nullptr)
					{
						try
						{
							cout << "Введите имя: ";  string name = ValidValue<string>::getInitials();
							cout << "Введите фамилию: "; string lastname = ValidValue<string>::getInitials();
							string adress;
							cout << "Введите адрес: "; getline(cin, adress);
							cout << "Введите номер карты: "; int cardNumber = ValidValue<>::getValue();
							system("cls");
							clientData = new ClientData(name, lastname, adress, cardNumber);
							order.setData(clientData);
						}
						catch (bad_alloc ex)
						{
							cout << "ERROR: " << ex.what() << "!" << endl << endl;
						}
						catch (ExpShop ex)
						{
							cout << ex.what() << endl << endl;
						}
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
					if (DepartmentManager::showGoods(shop.getComputerDep()))
					{
						cout << endl << "Выберите номер товара: ";
						bool isValidInput = false;
						while (!isValidInput)
						{
							try
							{
								ch = ValidValue<>::getValue();
								if (ch <  1 || ch > shop.getComputerDep().getGoods().size())
								{
									throw ExpShop("error", 1);
								}
								isValidInput = true;
							}
							catch (ExpShop ex)
							{
								cout << ex.what();
							}
						}
						

						device = DepartmentManager::removeGood(ch - 1, shop.getComputerDep());
						OrderManager::addGood(device, order);
						system("cls");
					}
					else
					{
						cout << "В компьютерном отделе закончился товар!" << endl << endl;
					}
				}
					break;

				case 3:
				{
					int ch = 0;
					ElectricalDevices* device = nullptr;
					if (DepartmentManager::showGoods(shop.getHouseholdDep()))
					{
						bool isValidInput = false;
						while (!isValidInput)
						{
							try
							{
								ch = ValidValue<>::getValue();
								if (ch < 1 || ch > shop.getHouseholdDep().getGoods().size())
								{
									throw ExpShop("error", 1);
								}
								isValidInput = true;
							}
							catch (ExpShop ex)
							{
								cout << ex.what();
							}
						}
						device = DepartmentManager::removeGood(ch - 1, shop.getHouseholdDep());
						OrderManager::addGood(device, order);
					system("cls");
					}
					else
					{
						cout << "В бытовом отделе закончился товар!" << endl << endl;
					}
				}
					break;

				case 4:
					if (!OrderManager::showGoods(order))
					{
						cout << "~~~ЗАКАЗ~~~" << endl;
						cout << "Нет товаров!" << endl;
					}
					system("pause>>void");
					system("cls");
					break;

				case 5:
				{
					int ch = 0;
					if (OrderManager::showGoods(order))
					{
						cout << "Выберите товар, который хотите убрать: ";
						bool isValidInput = false;
						while (!isValidInput)
						{
							try
							{
								ch = ValidValue<>::getValue();
								if (ch < 1 || ch > order.getGoods().size())
								{
									throw ExpShop("error", 1);
								}
								isValidInput = true;
							}
							catch (ExpShop ex)
							{
								cout << ex.what();
							}
						}

						ElectricalDevices* good = OrderManager::removeGood(ch - 1, order);
						switch (good->getType())
						{
						case HOUSEHOLD:
							DepartmentManager::addGood(good, shop.getHouseholdDep());
							break;

						case COMPUTER:
							DepartmentManager::addGood(good, shop.getComputerDep());
							break;

						default:
							break;
						}
						system("cls");
					}
					else
					{
						cout << "В заказе ещё нет товаров!" << endl << endl;
					}
				}
					break;

				case 6:
				{
					if (clientData != nullptr && OrderManager::showGoods(order))
					{
						cout << endl;
						cout << "Общая сумма: " << order.getTotalSum() << "$" << endl;
						system("pause>>void");
						system("cls");
						ch = 7;
						choice = 4;
					}
					else
					{
						cout << "Список товар пуст или данные о клиенте ещё не заполнены!" << endl << endl;
					}
				}
					break;

				case 7:
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


void term_func()
{
	system("cls");
	cout << "Ошибка! Программа завершает свою работу!" << endl;
	system("pause>>void");
	exit(0);
}
