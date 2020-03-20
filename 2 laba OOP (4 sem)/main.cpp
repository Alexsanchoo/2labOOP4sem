#include<iostream>
#include<Windows.h>
#include "Shop.h"
#include "ClientData.h"
#include "Order.h"

using namespace std;


//template<typename T>
//T getValue()
//{
//	T k;
//	while (true)
//	{
//		try
//		{
//			cin >> k;
//			cin.ignore(2,'\n');
//			if (cin.gcount() > 1) throw runtime_error("extra characters");
//			return k;
//		}
//		catch (runtime_error ex)
//		{
//			cout << "error: " << ex.what() << endl;
//			cin.clear();
//			while (cin.get() != '\n');
//		}
//	}
//}


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
		choice = 0; //изменить

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


/*
	Отдел: коструктор копирования
	Заказ: конструктор копирования
*/