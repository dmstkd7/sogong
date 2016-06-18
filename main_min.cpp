#include "lib.h"
#include "total.h"
using namespace std;


//전체 판매를 관리하는 


int Item::markItemID = 0;
Client CurrentUser(1, "guest", "guest");
SellItemCollection SellItemCollect;
FinishItemCollection FinishItemCollect;
BidItemCollection BidItemCollect;

//현재시간을 나타내는 전역변수
Day CurrentTime;


int main(void)
{
	//시간초기화 나중에 클래스로 예쁘게 구현해야 한다
	//오퍼레이션 하셨다는게 어떤걸 의미하는지 내일 여쭤보자
	CurrentTime.year = 2016;
	CurrentTime.month = 6;
	CurrentTime.day = 1;
	CurrentTime.hour = 12;


	int command;

	//지금 현재 유저가 누구인지 나타내주는 클래스이다
	while (1) {
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

		switch (command) {
		case 1:break;
		case 2:break;

			// 판매물품등록관리로 넘어간다
		case 3:
			managementRegisterItem();
			break;
			// 내 파트
		case 4:
			managementBIdItem(CurrentUser, BidItemCollect, SellItemCollect);
			break;
		case 5:break;
		case 6:
			setCurrentTime();
			break;
		case 7:

			break;
		case 0: return 0;
		default:
			cout << "알맞지 않는 번호입니다";
			break;
		}
	}

	return 0;
}
