#include<iostream>
#include<Windows.h>

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
	
	int choice = 0;
	while (choice != 8)
	{
		cout << "~~~СБОРКА КОМПЬЮТЕРА~~~" << endl;
		cout << "1. Оперативная память" << endl;
		cout << "2. Жесткий диск" << endl;
		cout << "3. Блок питания" << endl;
		cout << "4. Система охлаждения процессора" << endl;
		cout << "5. Периферийные устройства" << endl;
		cout << "6. Материнская плата" << endl;
		cout << "7. Включить компьютер" << endl;
		cout << "8. Выход" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
			system("cls");
			break;

		case 5:
			system("cls");
			break;

		case 6:
			system("cls");
			break;

		case 7:
			system("cls");
			break;

		case 8:
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
	*/