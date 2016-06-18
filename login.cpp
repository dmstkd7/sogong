#include "loginsignUp.h"


/*============================Client=====================================*/

void Client::setName(string c_name) { name = c_name; }
void Client::setPrivateNumber(int c_praivateNumber) { privateNumber = c_praivateNumber; }
void Client::setAddress(string c_address) { address = c_address; }
void Client::setEmail(string c_email) { email = c_email; }
void Client::setId(string c_id) { id = c_id; }
void Client::setPassword(string c_password) { password = c_password; }
void Client::setSession(int c_session) { session = c_session; }

string Client::getName() { return name; }
int Client::setPrivateNumber() { return privateNumber; }
string Client::setAddress() { return address; }
string Client::setEmail() { return email; }
string Client::getId() { return id; }
string Client::getPassword() { return password; }
int Client::getSession() { return session; }



//클라이언트 정보를 프린트 해주는 함수입니다
void Client::Print() {

	cout << "Name : " << name << endl;
	cout << "address :" << address << endl;
	cout << "email : " << email << endl;
	cout << "id :" << id << endl;
	cout << "password : " << password << endl;
}



/*==================================ClientCollection===========================================================*/


/*======================== 회 원  가 입   회 원 탈 퇴======================*/
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
			ClientCollect.signUp(currentUser);




			break;

		case 2:
			cout << "2. 회원 탈퇴." << endl;
			if (1 == ClientCollect.deleteClient(currentUser)) { cout << "탈퇴 완료" << endl; }
			else { cout << "탈퇴안됨" << endl; }
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
	//currentUser.setName(str);


	cout << "address 입력 : ";
	cin >> str;
	totalClient[newMember].setAddress(str);
	//currentUser.setAddress(str);

	cout << "email 입력 : ";
	cin >> str;
	totalClient[newMember].setEmail(str);
	//currentUser.setEmail(str);

	cout << "id 입력 : ";
	cin >> str;
	totalClient[newMember].setId(str);
	//currentUser.setId(str);

	cout << "password 입력 : ";
	cin >> str;
	totalClient[newMember].setPassword(str);
	//currentUser.setPassword(str);

	n[newMember] = true;

	totalClient[newMember].setPrivateNumber(newMember);
	//currentUser.setPrivateNumber(newMember);

}



bool ClientCollection::deleteClient(Client currentUser) {
	int checkNum = 0;
	string inputId;
	string inputPassword;

	cout << "id를 입력하세요 : ";
	cin >> inputId;


	if (totalClient[checkNum].getName() == "")
		cout << "오류 " << endl;

	for (; totalClient[checkNum].getId() != inputId && checkNum<10; checkNum++);
	if (checkNum == 10) {
		cout << "일치하는 id가 없습니다." << endl;
		return 0;
	}
	else{
		cout << "password를 입력하세요 : ";
		cin >> inputPassword;
		if (totalClient[checkNum].getPassword() == inputPassword) {
			bool d;
			cout << "탈퇴하시겠습니까? Y (1) /N (0)  : ";
			cin >> d;
			if (d == 1) {
				cout << "회원탈퇴가 완료되었습니다. " << endl;
				totalClient[checkNum].setName("");
				totalClient[checkNum].setAddress("");
				totalClient[checkNum].setEmail("");
				totalClient[checkNum].setId("");
				totalClient[checkNum].setPassword("");
				n[checkNum] = false;
				return 1;
			}
			else
				cout << "회원탈퇴가 취소되었습니다." << endl;

			return 0;
		}
		else
			cout << "비밀번호가 일치하지 않습니다."  << endl;
	}
	return 0;

}


/*======================== 로 그 인   로 그 아 웃======================*/



void ClientCollection::Login_Logout(Client currentUser, ClientCollection ClientCollect) {
	int command = 0;

	//Client *CurrentUser = new Client(1, "guest");


	cout << "1. 로그인" << endl;
	cout << "2. 로그아웃" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;

	cout << "* 입력 선택 : ";
	cin >> command;

	//로그인이 되어 있는지 없는지 확인해주는 변수입니다
	bool isLogin = false;
	isLogin = (currentUser.getSession() == 1);

	switch (command) {
	case 1:
		cout << "1. 로그인." << endl;
		if (isLogin && ClientCollect.Login(currentUser)) { cout << "로그인 성공"<< endl; }
		else { cout << "로그인 실패" << endl; }

		break;

	case 2:
		cout << "2. 로그아웃." << endl;
	//	ClientCollect.deleteClient(currentUser, ClientCollect);
		break;

	case 0:
		cout << "메인 메뉴로 돌아갑니다." << endl;
		break;

	default:
		cout << "알맞지 않는 번호입니다";
		break;
	}

}


//currentUser의 상태를 받아서 로그인이 되었다면
//currentUser의 id, session 등등을 로그인된 정보로 바꾼다

bool ClientCollection::Login(Client currentUser) {
	int checkNum = 0;
	string inputId;
	string inputPassword;

	//ClientCollect.PrintAll(totalClient[0]);
	cout << "id를 입력하세요 : ";
	cin >> inputId;

	for (; totalClient[checkNum].getId().compare(inputId) == 0 && checkNum < 10; checkNum++);
	if (checkNum == 10) {
		cout << "일치하는 아이디가 없습니다." << endl;
		return false;
	}

	for (int i = 0; i < 3; i++) {
		cout << "PW를 입력하세요 : ";
		cin >> inputPassword;

		if (totalClient[checkNum].getPassword() != inputPassword) {
			cout << "로그인실패 !" << endl;
			return false;
		}
		else {
			cout << "로그인 성공!" << endl ;//"비밀번호가 일치하지 않습니다." << "(기회 : " << 2 - i << "번 남음)" << endl;
			return true;

		}
	}
}
//|| totalClient[checkNum].getPassword() != inputPassword) 

bool ClientCollection::Logout(int a) {


	bool l;

	cout << "정말 로그아웃 하시겠습니까? Y(1) / N(0) : ";
	cin >> l;
	if (l == 1) {
		cout << " 로그아웃 완료 " << endl;
		return 1;
	}
	else
		cout << "전 단계로 돌아가." << endl;
	return 0;
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
