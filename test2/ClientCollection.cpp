#include "ClientCollection.h"

void ClientCollection::signUp_deleteClient(Client currentUser, ClientCollection ClientCollect) {
	int command = 0;

	//Client *CurrentUser = new Client(1, "guest");


	cout << "1. 회원 가입" << endl;
	cout << "2. 회원 탈퇴" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;
	cout << "* 입력 선택 : ";
	cin >> command;

	switch (command) {
	case 1:
		cout << "1. 회원 가입." << endl;
		//		ClientCollect.signUp(currentUser, ClientCollect);
		//	ClientCollect.PrintAll(currentUser);
		ClientCollect.signUp(currentUser);
		//	ClientCollect.PrintAll(totalClient[0]);
		break;

	case 2:
		cout << "2. 회원 탈퇴." << endl;
		//			ClientCollect.PrintAll(totalClient[0]);
		//			if (1 == ClientCollect.deleteClient(currentUser)) { cout << "탈퇴 완료" << endl; }
		//			else { cout << "탈퇴안됨" << endl; }
		//			ClientCollect.PrintAll(totalClient[0]);
		break;

	case 0:
		cout << "메인 메뉴로 돌아갑니다." << endl;
		break;

	default:
		cout << "알맞지 않는 번호입니다";
		break;
	}

}


void ClientCollection::signUp(Client currentUser) {

	string str = "";
	int newMember = 0;
	for (; n[newMember] != 0; newMember++);

	cout << "name 입력 : ";
	cin >> str;
	totalClient[newMember].setName(str);
	currentUser.setName(str);


	cout << "address 입력 : ";
	cin >> str;
	totalClient[newMember].setAddress(str);
	currentUser.setAddress(str);

	cout << "email 입력 : ";
	cin >> str;
	totalClient[newMember].setEmail(str);
	currentUser.setEmail(str);

	cout << "id 입력 : ";
	cin >> str;
	totalClient[newMember].setId(str);
	currentUser.setId(str);

	cout << "password 입력 : ";
	cin >> str;
	totalClient[newMember].setPassword(str);
	currentUser.setPassword(str);

	n[newMember] = true;

	//totalClient[newMember].setPrivateNumber(newMember);
	//currentUser.setPrivateNumber(newMember);

}