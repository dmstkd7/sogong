#include "lib.h"
using namespace std;


class Client{
private:

	//0은 admin, 1 guest, 2 user
	int c_session;
	string c_name;
	string c_private_number;
	string c_address;
	string c_email;
	string c_id;
	string c_password;

	//비더 , 셀러

public:
	
	//get, set 구현할것
	//생성자 구현할것

	Client(int session, string name){
		c_session = session;lib
		c_name = name;
	}

};


int main(void)
{
	//어디로 넘어갈지 정해주는 변수
	int state;

	Client *CurrentUser = new Client(1,"guest");
	
	cout << "1. Login/Logout" << endl;
	cout << "2. Session 선택/변경" << endl;
	cout << "3. 물품 등록 관리" << endl;
	cout << "4. 경매 물품 조회, 입찰 관리" << endl;
	cout << "5. 구매 완료/낙찰 실패 물품 정보 확인" << endl;
	cout << "6. 경과시간 입력" << endl;
	cout << "7. 회원가입/탈퇴" << endl;
	cout << "0. 종료" << endl;

	cout << "* 입력 선택 : ";
	cin >> state;

	switch (state){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 0:
		default:
			cout << "알맞지 않는 번호입니다"
			break;
			

	}
	



	return 0;
}
