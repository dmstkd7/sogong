#pragma once
#include "Client.h"
#include <iostream>
using namespace std;

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

//	void PrintAll(Client currentUser);  // Client의 정보를 확인할 수 있는 함수입니다.

};
