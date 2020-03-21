#pragma once
#include<iostream>
#include<string>

using namespace std;

template<typename T = int>
class ValidValue
{
public:
	static T getValue();
};

template<typename T>
inline T ValidValue<T>::getValue()
{
	T value;
	while (true)
	{
		try
		{
			cin >> value;
			cin.ignore(2, '\n');
			if (cin.gcount() > 1) throw runtime_error("extra characters");
			return value;
		}
		catch (runtime_error ex)
		{
			cout << ex.what();
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
