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
	
	Shop shop("�������-��������");
	ClientData clientData("�������", "������", "��. �������, �. �����������", 228543573);
	Order order(&clientData);
		
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
		choice = 0; //��������

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
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
	return 0;
}

/*
	1. ������� ������������
	2. ������ ������������ (����������)
	3. ����������� ����� - ������� (������ ������ �������) (��������� � ����� � ������)
	4. �����
	5. ������ ������� (���������� � ������)
*/


/*
	�����: ���������� �����������
	�����: ����������� �����������
*/