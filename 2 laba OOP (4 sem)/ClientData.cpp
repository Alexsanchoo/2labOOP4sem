#include "ClientData.h"

void ClientData::setName(string name)
{
	this->name = name;
}

void ClientData::setLastname(string lastname)
{
	this->lastname = lastname;
}

void ClientData::setAdress(string adress)
{
	this->adress = adress;
}

void ClientData::setCardNumber(int number)
{
	cardNumber = number;
}

string ClientData::getName()
{
	return name;
}

string ClientData::getLastname()
{
	return lastname;
}

string ClientData::getAdress()
{
	return adress;
}

int ClientData::getCardNumber()
{
	return cardNumber;
}

void ClientData::set()
{
	cout << "������� ���: "; name = ValidValue<string>::getInitials();
	cout << "������� �������: "; lastname = ValidValue<string>::getInitials();
	cout << "������� �����: "; adress = ValidValue<string>::getString();
	cout << "������� ����� �����: "; cardNumber = ValidValue<>::getValue();
}
