#include "memberManagement.h"

void ClientCollection::SignUp() {

	string str = "";
	int newMember = 0;
	for (; n[newMember] != 0; newMember++);

	//while (str == "") {
	cout << "name 입력 : ";
	cin >> str;
	//	if (str == "\n") { cout << "name 을 입력하세요"; }
	//	else
	totalClient[newMember].MakeName(str);
	//}


	//cout << "praivateNum 입력 : ";
	//cin >> str;
	//totalClient[newMember].MakePN(str);

	cout << "address 입력 : ";
	cin >> str;
	totalClient[newMember].MakeADD(str);

	cout << "email 입력 : ";
	cin >> str;
	totalClient[newMember].MakeEMAIL(str);

	cout << "ID 입력 : ";
	cin >> str;
	totalClient[newMember].MakeID(str);

	cout << "PW 입력 : ";
	cin >> str;
	totalClient[newMember].MakePW(str);

	n[newMember] = true;

}

void Client::MakeName(string str)
{
	name = str;
}
//void MakePN(string str) { praivateNum = str; }
void Client::MakeADD(string str)
{
	address = str;
}
void Client::MakeEMAIL(string str)
{
	email = str;
}
void Client::MakeID(string str)
{
	ID = str;
}
void Client::MakePW(string str)
{
	PW = str;
}


//void Client::Print() {
//
//	cout << "Name : " << name << endl;
//	cout << "address :" << address << endl;
//	cout << "email : " << email << endl;
//	cout << "ID :" << ID << endl;
//	cout << "PW : " << PW << endl;
//}
//
//void ClientCollection::PrintAll() {
//	//for (int newMember = 0; newMember < 10; newMember++)
//	//{
//		totalClient[0].Print();
//	//}
//}


