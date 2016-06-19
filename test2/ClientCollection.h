#pragma once
#include "Client.h"
#include <iostream>
using namespace std;

class ClientCollection {
private:
	Client* totalClient = new Client[10];
	bool n[10];

public:
	ClientCollection() {
		for (int i = 0; i < 10; i++)
			n[i] = false;
	};
	~ClientCollection() { delete[] totalClient; }

	void signUp_deleteClient(Client currentUser, ClientCollection ClientCollect);
	void signUp(Client currentUser);
	bool deleteClient(Client currentUser);

	void Login_Logout(Client currentUser, ClientCollection ClientCollect);
	bool Login(Client currentUser);
	int Logout(int);

	//void printClient();
	//	void PrintAll(Client currentUser);  //// 정보 입력 확인 용

};