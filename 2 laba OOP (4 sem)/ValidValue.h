#pragma once
#include<iostream>
#include<string>
#include<regex>

using namespace std;

template<class T = int>
class ValidValue
{
public:
	static T getValue();
	static string getInitials();
	static string getString();
};

template<class T>
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

inline string ValidValue<string>::getInitials()
{
	string validStr;
	bool isValid = false;
	while (!isValid)
	{
		getline(cin, validStr);
		isValid = regex_match(validStr, regex("[A-ZÀ-ß¨][a-zà-ÿ¸]+"));
		if (!isValid)
		{
			cout << "Îøèáêà! Ââåäèòå åù¸ ðàç: ";
		}
	}
	return validStr;
}

inline string ValidValue<string>::getString()
{
	string validStr;
	bool isValid = false;
	while (!isValid)
	{
		getline(cin, validStr);
		isValid = regex_match(validStr, regex("[À-ßà-ÿA-Za-z¨¸\\-\\ ]+"));
		if (!isValid)
		{
			cout << "Îøèáêà! Ââåäèòå åù¸ ðàç: ";
		}
	}
	return validStr;
}
