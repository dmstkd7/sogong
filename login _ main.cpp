

	ClientCollection ClientCollect;
	Client currentUser(1, "guest");

void main() {

	//지금 현재 유저가 누구인지 나타내주는 클래스이다
	Client *currentUser = new Client(1, "guest");
	
//ClientCollection * ClientCollect = new ClientCollection();


	//어디로 넘어갈지 정해주는 변수Qh
	int command = 1;

	while (1) {
		cout << "1. Login/Logout" << endl;
		cout << "7. 회원가입/탈퇴" << endl;
		cout << "0. 종료" << endl;

		cout << "* 입력 선택 : ";
		cin >> command;

		switch (command) {
		case 1:
			cout << "1. 로그인/ 로그아웃으로 넘어갑니다." << endl;
			ClientCollect.Login_Logout(*currentUser, ClientCollect);
		
			break;

		case 7:
			cout << "7. 회원가입/탈퇴로 넘어갑니다." << endl;
			ClientCollect.signUp_deleteClient(*currentUser, ClientCollect) ;
			break;

		case 0:
			cout << "0. 프로그램 종료" << endl;

			break;
		default:
			cout << "알맞지 않는 번호입니다." << endl;
			break;
		}
	
	}

}
