#include "lib.h"
#include "total.h"
using namespace std;


//전체 판매를 관리하는 



int main(void)
{
	//어디로 넘어갈지 정해주는 변수
	int command;

	//지금 현재 유저가 누구인지 나타내주는 클래스이다
	Client *CurrentUser = new Client(1,"guest");
	SellItemCollection *SellItemCollect = new SellItemCollection();
	
	
	cout << "1. Login/Logout" << endl;
	cout << "2. Session 선택/변경" << endl;
	cout << "3. 물품 등록 관리" << endl;
	cout << "4. 경매 물품 조회, 입찰 관리" << endl;
	cout << "5. 구매 완료/낙찰 실패 물품 정보 확인" << endl;
	cout << "6. 경과시간 입력" << endl;
	cout << "7. 회원가입/탈퇴" << endl;
	cout << "0. 종료" << endl;

	cout << "* 입력 선택 : ";
	cin >> command;

	switch (command){
		case 1:break;
		case 2:break;

		//판매물품등록관리로 넘어간다
		case 3:
			managementRegisterItem(*CurrentUser, *SellItemCollect);
			break;
		case 4:break;
		case 5:break;
		case 6:break;
		case 7:
			
			break;
		case 0:break;
		default:
			cout << "알맞지 않는 번호입니다";
			break;
			

	}
	
	return 0;
}
