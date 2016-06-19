#include "loginSignup.h"

ClientCollection ClientCollect;
Client currentUser(1, "guest");

void main() {

	//어디로 넘어갈지 정해주는 변수
	int command = 1;

	while (1) {
		cout << "1. Login/Logout" << endl;
		cout << "7. 회원가입/탈퇴" << endl;
		cout << "0. 종료" << endl;

		cout << "* 입력 선택 : ";
		cin >> command;

		switch (command) {
		case 1:
			cout << "********로그인/ 로그아웃을 선택해주세요**************" << endl;
			ClientCollect.Login_Logout();
			break;

		case 7:
			cout << "********회원 가입/ 회원 탈퇴를 선택해주세요**************." << endl;
			ClientCollect.signUp_deleteClient();
			break;

		case 0:
			cout << "*********프로그램을 종료합니다.************" << endl;
			return;
			break;
		default:
			cout << "알맞지 않는 번호입니다." << endl;
			break;
		}

	}

}

