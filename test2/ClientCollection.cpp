#include "ClientCollection.h"

// 회원 가입과 회원 탈퇴 중 선택하는 창입니다.
void ClientCollection::signUp_deleteClient() {
	int command = 0;

	cout << "1. 회원 가입" << endl;
	cout << "2. 회원 탈퇴" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;

	cout << "* 입력 선택 : ";
	cin >> command;

	switch (command) {
	case 1:
		cout << "************** 회원가입 하러 오셨군요 반갑습니다 **************" << endl;
		if (currentUser.getId()!="!!!"){ cout << "로그아웃 후 가입이 가능합니다." << endl; }
		else { 
			ClientCollect.signUp(); }
		break;

	case 2:
		cout << "************** 회원탈퇴 하러 오셨군요 반갑습니다 **************" << endl;
		// currentUser만이 탈퇴가 가능하다
		if (currentUser.getId() == "!!!") {
			cout << "로그인 후 탈퇴가 가능합니다." << endl;		}
		else{
			if (ClientCollect.deleteClient(currentUser) == true) { cout << "탈퇴가 완료되었습니다." << endl; }

			else { cout << "탈퇴가 취소되었습니다." << endl; }
		}
			
		break;

	case 0:
		cout << "메인 메뉴로 돌아갑니다." << endl;
		return;
		break;

	default:
		cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요";	
		break;
	}

}

//회원 가입을 하는 창입니다.
void ClientCollection::signUp() {
	string str ;
	Client newClient;

	int newMember = 0;
	for (;totalClient[newMember].getId() != "!!!"; newMember++);
	
	try {
	cout << "name 입력(15자 이하 가능) : ";
	cin >> str;
	if (str.length() > 15) throw 1;	
	newClient.setName(str);//몇 번째 값에 Name을 설정할 것인지 정하는 함수입니다
	
	cout << "address 입력(30자 이하 가능) : ";
	cin >> str;
	if (str.length() > 30) throw 2;
	newClient.setAddress(str);

	cout << "email 입력(30자 이하 가능)  : ";
	cin >> str;
	if (str.length() > 30) throw 3;
	newClient.setEmail(str);

	cout << "id 입력(15자 이하 가능)  : ";
	cin >> str;
	if (str.length() > 15) throw 4;
	newClient.setId(str);

	cout << "password 입력(20자 이하 가능)  : ";
	cin >> str;
	if (str.length() > 20) throw 5;
	newClient.setPassword(str);
	
	newClient.setPrivateNumber(newMember);
	
	//입력 받은 값들을 Collection의 client에 저장하는 함수입니다.
	ClientCollect.setTotalClient(newMember, newClient);
	
	}
	
	catch (int type) {
		switch (type)
		{
		case 1:
			cout << "name은 15자를 넘어갈 수 없습니다." << endl;
			break;
		case 2:
			cout << "address는 30자를 넘어갈 수 없습니다." << endl;
			break;
		case 3:
			cout << "email은 30자를 넘어갈 수 없습니다." << endl;
			break;
		case 4:
			cout << "id는 15자를 넘어갈 수 없습니다." << endl;
			break;
		case 5:
			cout << "password는 20자를 넘어갈 수 없습니다." << endl;
			break;
		default:
			break;
		}
		
	}
	return;
}


//회원 탈퇴를 하는 창입니다.
// currentUser만이 탈퇴가 가능하다
bool ClientCollection::deleteClient(Client wantDeleteClient) {
	int checkNum = 0;
	string inputId;
	string inputPassword;

	cout << "id를 입력하세요 : ";
	cin >> inputId;

	if (wantDeleteClient.getId() != inputId) {
		cout << "id가 일치하지 않습니다." << endl;
		return false;
	}

	// 일치하는 ID를 확인후 Password를 입력받는다.
	else {
		cout << "PW를 입력하세요 : ";
		cin >> inputPassword;

		// 일치하는 ID와 맞는 Password를 확인한다.
		// ID와 PW가 올바른 경우 탈퇴 여부를 확인한다.
		if (wantDeleteClient.getPassword() != inputPassword) {
			cout << "PW가 일치하지 않습니다. " << endl;
			return false;
		}
		else {
			int deleteCheck;
			cout << "탈퇴하시겠습니까? Y (1) /N (0)  : ";
			cin >> deleteCheck;

			//Y 를 선택하는 경우 CliectCollection에서 회원의 정보를 삭제 시킨다.
			// 현재 사용자의 정보도 모두 리셋한다.
			if (deleteCheck == 1) {
				int a;
				a = wantDeleteClient.getPrivateNumber();

				totalClient[a].setSession(1);
				totalClient[a].setName("guest");
				totalClient[a].setPrivateNumber(-1);
				totalClient[a].setAddress("");
				totalClient[a].setEmail("");
				totalClient[a].setId("!!!");
				totalClient[a].setPassword("");

				currentUser.setSession(1);
				currentUser.setName("guest");
				currentUser.setPrivateNumber(-1);
				currentUser.setAddress("");
				currentUser.setEmail("");
				currentUser.setId("!!!");
				currentUser.setPassword("");

				return true;
			}
			else 
				return false;
		}
	}

}



/*======================== 로 그 인   로 그 아 웃======================*/



// 로그인과 로그아웃 중 선택하는 창입니다.
void ClientCollection::Login_Logout() {
	int command = 0;

	//Client *CurrentUser = new Client(1, "guest");


	cout << "1. 로그인" << endl;
	cout << "2. 로그아웃" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;

	cout << "* 입력 선택 : ";
	cin >> command;

	//로그인이 되어 있는지 없는지 확인해주는 변수입니다.
	// 로그인 되있으면 ID가 !!이 아니야 
	//		-> 로그인 불가능
	//  !!!이면 로그인 가능
	bool loginCheck = false;

	loginCheck = (currentUser.getId() == "!!!");


	switch (command) {
	case 1:
		//if (loginCheck && ClientCollect.Login(currentUser)) { cout << "로그인 성공" << endl; }
		cout << "************** 로그인 하러 오셨군요 반갑습니다 **************" << endl;

		//else { cout << "로그인 되어있다." << endl; }
		
		if (loginCheck == true){

			if (ClientCollect.Login() == true) {
				cout << "로그인 성공" << endl;
			}
			else {
				cout << "로그인 실패" << endl;
			}
		}
		else { cout << "이미 로그인 상태 입니다!!" << endl; }
		break;

	case 2:
		cout << "************** 로그아웃 하러 오셨군요 **************" << endl;

		if (loginCheck == false) {
			if (ClientCollect.Logout() == true) {
				cout << "로그아웃 완료" << endl;
			}
			else
				cout << "로그아웃 취소" << endl;
		}
		else 
				cout << "로그아웃이 불가능 합니다.  로그인을 먼저 해주세요!!!" << endl;

		
		//if (isLogin && ClientCollect.Login(currentUser) ) { cout << "로그아웃이 불가능 합니다." << endl; }
		//if else  (isLogin && ClientCollect.Logout(currentUser)) { cout << "로그아웃 성공" << endl; }

		//else { cout << "로그아웃 취소" << endl; }

		
		break;

	case 0:
		cout << "메인 메뉴로 돌아갑니다." << endl;
		return;
		break;

	default:
		cout << "알맞지 않는 번호입니다";
		break;
	}

}


//currentUser의 상태를 받아서 로그인이 되었다면
//currentUser의 id, session 등등을 로그인된 정보로 바꾼다

bool ClientCollection::Login(){//Client loginUser) {
	int checkNum = 0;
	string inputId;
	string inputPassword;
	
	cout << "id를 입력하세요 : ";
	cin >> inputId;


	//일치하는게 있을때까지 while문을 계속 돌린다 만약 일치하는게 있으면 checkNum을 유지한 체 빠져나온다
	while (checkNum < 10) {
		if (totalClient[checkNum].getId() == inputId)
			break;
		checkNum++;
	}

	if (checkNum == 10) {
		cout << "일치하는 아이디가 없습니다." << endl;
		return false;
	}

	cout << "PW를 입력하세요 : ";
	cin >> inputPassword;

	if (totalClient[checkNum].getPassword() == inputPassword) {
		//ID와 Password가 일치한다면 currentUser의 정보를 set한다.
		currentUser.setSession(2);	//	session은 사용자로 설정한다.
		currentUser.setName(totalClient[checkNum].getName());
		currentUser.setPrivateNumber(totalClient[checkNum].getPrivateNumber());
		currentUser.setAddress(totalClient[checkNum].getAddress());
		currentUser.setEmail(totalClient[checkNum].getEmail());
		currentUser.setId(totalClient[checkNum].getId());
		currentUser.setPassword(totalClient[checkNum].getPassword());

		return true;
	}

	return false;
}


bool ClientCollection::Logout() {

	bool logoutcheck;

	cout << "정말 로그아웃 하시겠습니까? Y(1) / N(0) : ";
	cin >> logoutcheck;

	if (logoutcheck == 1) {
		currentUser.setSession(1);
		currentUser.setName("guest");
		currentUser.setPrivateNumber(-1);
		currentUser.setAddress("");
		currentUser.setEmail("");
		currentUser.setId("!!!");
		currentUser.setPassword("");
		return true;
	}
	else
		return false;
}


//
//void ClientCollection::PrintAll(Client currentUser) {
//	//for (int newMember = 0; newMember < 10; newMember++)
//	//{
//	///	totalClient[newMember].Print();
//	currentUser.Print();
//	//}
//}
//
