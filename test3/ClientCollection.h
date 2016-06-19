#pragma once
#include "Client.h"
#include <iostream>
using namespace std;

extern Client CurrentUser;


// Class : ClientCollection
 // Description: Client의 정보를 모아놓는 ClientCollection class이다. 
 //  Client 10명의 정보를 저장할 수 있다. 
 //  로그인, 로그아웃, 회원가입, 회원탈퇴의 operation을 선언한다.
 // Created: 2015/6/15 13:00 pm
 // Author: 전주라
 // mail: j161021@hanmail.net
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

};
