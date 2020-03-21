#include<iostream>
#include<Windows.h>
#include "ValidValue.h"
#include "Shop.h"
#include "ClientData.h"
#include "Order.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);
	
	Shop shop("Электро-экспресс");
	ClientData clientData("Василий", "Пупкин", "ул. Пушкина, д. Колотушкина", 228543573);
	Order order(&clientData);
		
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
			system("cls");
			break;

		case 2:
			system("cls");
			break;

		case 3:
			system("cls");
			break;

		case 4:
			break;

		default:
			cout << "Неверный выбор!" << endl << endl;
			break;
		}
	}
	return 0;
}

/*
	1. Магазин электронники
	2. Отделы электронники (композиция)
	3. Абстрактный класс - техника (пойдут классы техники) (агрегация в отдел в вектор)
	4. Заказ
	5. Данные клиента (композиция в заказе)
*/
