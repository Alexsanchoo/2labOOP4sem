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
		cout << "~~~������ ����������~~~" << endl;
		cout << "1. ����������� ������" << endl;
		cout << "2. ������� ����" << endl;
		cout << "3. ���� �������" << endl;
		cout << "4. ������� ���������� ����������" << endl;
		cout << "5. ������������ ����������" << endl;
		cout << "6. ����������� �����" << endl;
		cout << "7. �������� ���������" << endl;
		cout << "8. �����" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	*/