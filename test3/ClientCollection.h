#pragma once
#include "Client.h"
#include <iostream>
using namespace std;

extern Client CurrentUser;


// Class : ClientCollection
 // Description: Client의 정보를 모아놓는 ClientCollection class이다. 
 //  Client 10명의 정보를 저장할 수 있다. 
 //  로그인, 로그아웃, 회원가입, 회원탈퇴의 operation을 선언한다.
 // Created: 2015/6/15 14:20 pm
 // Author: 전주라
 // mail: j161021@hanmail.net
class ClientCollection {
private:
	Client totalClient[10];
public:


	ClientCollection() {}
	~ClientCollection() {}

// Function : void setTotalClient(int inputNum, Client newClient)
 // Description: 입력받은 값을 clientCollection에 저장하는 함수입니다.
 // Parameters : int inputNumber , Client newClient
 // Return Value :  없음
//newClient에 가입정보를 가져와
//Client Collection에 있는 totalClient[inputNum]에 저장합니다.
 // Created: 2016/6/16 20:15 pm
 // Author: 전주라
	void setTotalClient(int inputNum, Client newClient);

	void signUp_deleteClient();

// Function : void singUp()
 // Description: 회원가입을 하는 함수입니다.
 // Parameters : 없음
 // Return Value :  없음
//str로 입력을 받습니다.
//새로운 Client인 newClient를 생성합니다.
// checkNum으로 Collection에 저장된 client의 정보를 확인한다.
// 이름, 주소, 주민번호, 이메일, ID, PW를 입력 받아 저장한다.
// 
 // Created: 2015/6/15 17:75 pm
 // Author: 전주라

	void signUp();
	bool deleteClient(Client wantDeleteClient);

	void Login_Logout();
	bool Login();
	bool Logout();

};
