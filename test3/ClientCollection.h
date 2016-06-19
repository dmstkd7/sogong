#pragma once
#include "Client.h"
#include <iostream>
using namespace std;


extern Client CurrentUser;

class ClientCollection {
private:
	Client totalClient[10];
public:


	ClientCollection() {}
	~ClientCollection() {}

	void setTotalClient(int inputNum, Client newClient);

	void signUp_deleteClient();
	void signUp();
	bool deleteClient(Client wantDeleteClient);

	void Login_Logout();
	bool Login();
	bool Logout();

	//void printClient();
	//	void PrintAll(Client currentUser);  //// 정보 입력 확인 용

};