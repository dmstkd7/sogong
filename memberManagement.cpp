#include "memberManagement.h"

void Client::SetName(string str)
{
	c_name = str;
}
//void SetPN(string str) { praivateNum = str; }
void Client::SetADD(string str)
{
	c_address = str;
}
void Client::SetEMAIL(string str)
{
	c_email = str;
}
void Client::SetID(string str)
{
	c_ID = str;
}
void Client::SetPW(string str)
{
	c_PW = str;
}

void Client::SetPRIVATENUM(int i)
{
	c_privateNum = i;
}

int Client::GetPrivateNum() {
	return c_privateNum;
}



void ClientCollection::SignUp() {	//  회원가입  : name, address, email, ID, PW를 입력한다.

	string str = "";
	int newMember = 0;
	for (; n[newMember] != 0; newMember++);

	//while (str == "") {
	cout << "name 입력 : ";
	cin >> str;
	//	if (str == "\n") { cout << "name 을 입력하세요"; }
	//	else
	totalClient[newMember].SetName(str);
	//}

	cout << "address 입력 : ";
	cin >> str;
	totalClient[newMember].SetADD(str);

	cout << "email 입력 : ";
	cin >> str;
	totalClient[newMember].SetEMAIL(str);

	cout << "ID 입력 : ";
	cin >> str;
	totalClient[newMember].SetID(str);

	cout << "PW 입력 : ";
	cin >> str;
	totalClient[newMember].SetPW(str);

	n[newMember] = true;

}



void Client::Print() {					//회원가입시 입력한 회원정보 확인하려는 함수
		
	cout << "Name : " << c_name << endl;
	cout << "address :" << c_address << endl;
	cout << "email : " << c_email << endl;
	cout << "ID :" << c_ID << endl;
	cout << "PW : " << c_PW << endl;
	cout << "privateNum : " << c_privateNum << endl;

}

void ClientCollection::PrintAll() {		    //회원가입시 입력한 회원정보 확인하려는 함수
	//for (int newMember = 0; newMember < 10; newMember++)
	//{
		totalClient[0].Print();
	//}
}

