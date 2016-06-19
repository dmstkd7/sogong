// Class : utility.h
 // Description: 메인에서 쓸 함수를 한 데 모아둔 것입니다
 // Created: 2016/6/20 02:11 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 22016/6/20 02:11 pm 02:30 pm by EunsangJang
 //      What : 팀원과 합치는 과정에서 queryBidItem, queryMyBidItem, managemnetRegisterItem()등을 추가하였습니다

#include "utility.h"
#include "collection.h"

extern Day CurrentTime;
extern Client CurrentUser;


// Function : void querySellItem();
 // Description: 판매중인 것을 조회하는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:12 pm
 // Author: 장은상
void querySellItem(){
	cout << "************** 판매중인 물품 정보 조회 하러 오셨군요 반갑습니다 **************" << endl;
	SellItemCollect.getSellItemList();
	return;
}

// Function : void queryFinishItem();
 // Description: 판매가 완료된 것을 조회하는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:18 pm
 // Author: 장은상
void queryFinishItem(){
	cout << "************** 판매/종료 유찰 조회 하러 오셨군요 반갑습니다 **************" << endl;
	FinishItemCollect.addFinishItem();
	FinishItemCollect.getFinishItemList();
	return;
}

// Function : void changeSession();
 // Description: CurrentUser의 Session을 바꿔주는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:29 pm
 // Author: 장은상
void changeSession(){
	cout << "************** 세션을 바꾸러 오셨군요 반갑습니다 **************" << endl;
	int command;

	cout << "1.Admin" << endl;
	cout << "2.Guest" << endl;
	//이게 유저를 의미하는건지 아닌지 모르겠다
	cout << "3.User" << endl;
	cout << "0.메인 메뉴로 돌아가기" << endl;
	cin >> command;

	switch (command){
	case 1:
		CurrentUser.setSession(0);
		//cout << "현재 커런트 정보 " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 2:
		CurrentUser.setSession(1);
		//cout << "현재 커런트 정보 " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 3:
		CurrentUser.setSession(2);
		//cout << "현재 커런트 정보 " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 0:
		return;
	default:
		cout << "잘못된 값을 입력하셨습니다 세션 바꾸기를 종료합니다" << endl;
		break;
	}

}


// Function : void managementRegisterItem();
 // Description: 판매물품등록을 하기 위한 곳으로 가는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 // Created: 2016/6/20 02:51 pm
 // Author: 장은상
void managementRegisterItem(){

	int command;
	while (1){
		cout << "1. 판매 물품 정보 등록" << endl;
		cout << "2. 판매 중인 물품 정보 조회" << endl;
		cout << "3. 판매 종료/유찰 물품 조회" << endl;
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "입력 선택 : ";

		cin >> command;
		if (command == 0) return;

		switch (command){
		case 1:
			cout << "1. 판매 물품 정보 등록으로 들어갑니다" << endl;
			SellItemCollect.addSellItem();
			break;
		case 2:
			cout << "2. 판매 중인 물품 정보 조회로 들어갑니다." << endl;
			querySellItem();
			break;
		case 3:
			cout << "3. 판매 종료/유찰 물품 조회" << endl;
			queryFinishItem();
			break;
		case 0:
			cout << "0. 메인 메뉴로 돌아가겠습니다" << endl;
			return;
			break;
		default:
			cout << "명령어 입력이 올바르지 않습니다. 다시 입력해주세요" << endl;
			continue;

		}
	}
	return;

}

// Function : void setCurrentTime();
 // Description: 현재 시간을 바꿔주는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 // Created: 2016/6/20 03:11 pm
 // Author: 장은상
void setCurrentTime(){
	//경과시간을 어떻게 입력시키지

	cout << "************** 경과시간을 입력하는 곳입니다. **************" << endl;
	cout << "현재시간은" << CurrentTime.year << "년 " << CurrentTime.month << "월 " << CurrentTime.day << "일 " << CurrentTime.hour << "시간 " << endl;
	//int tmp;
	/*
	cout << "경과 시간을 입력하시오";
	cin >> tmp;
	CurrentTime.passTime(tmp);
	*/
	
	int tmp;
	while (1){
		try{
			cout << "몇 년으로 설정하시겠습니까 : ";
			cin >> tmp;
			CurrentTime.year = tmp;
			if (CurrentTime.year < 0) throw 1;
			cout << "몇 월으로 설정하시겠습니까 : ";
			cin >> tmp;
			CurrentTime.month = tmp;
			if (CurrentTime.month < 0 || CurrentTime.month > 12) throw 1;
			cout << "몇 일으로 설정하시겠습니까 : ";
			cin >> tmp;
			CurrentTime.day = tmp;
			if (CurrentTime.day < 0 || CurrentTime.day > 31) throw 1;
			cout << "몇 시간으로 설정하시겠습니까 : ";
			cin >> tmp;
			CurrentTime.hour = tmp;
			if (CurrentTime.hour < 0 || CurrentTime.hour > 24) throw 1;
			break;
		}
		catch (int type){
			if (type == 1){
				cout << "올바른 경과시간을 입력해주시기 바랍니다. ";
			}
		}
	}
	

	cout << "바뀐 현재시간은 " << CurrentTime.year << "년 " << CurrentTime.month << "월 " << CurrentTime.day << "일 " << CurrentTime.hour << "시간 " << endl;


}


// Function : void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
 // Description: 구매물품등록을 하기 위한 곳으로 가는 함수입니다
 // Parameters :  Client currentUser - 현재 유저의 정보를 담은 클래스
 //               BidItemCollection BidItemCollect - 현재 존재하는 BidItemCollection
 //               SellItemCollection SellItemCollect - 현재 존재하는 SellitemCollection
 // Return Value : 없음
 // Created: 2016/6/19 02:11 pm
 // Author: 최민수
void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect) {
	int command = 0;
	while (1) {
		cout << "- 4. 경매 물품 조회, 입찰 관리" << endl;
		cout << "1. 경매 중인 물품 조회" << endl;
		cout << "2. 참여 중인 입찰 조회" << endl;
		cout << "0. 메인메뉴로 돌아가기" << endl;

		cout << "* 입력선택 : ";
		cin >> command;
		switch (command) {
		case 0: return;
		case 1: queryBidItem(currentUser, BidItemCollect, SellItemCollect); return;
		case 2: queryMyBidItem(currentUser, BidItemCollect); return;
		default:
			cout << "알맞지 않은 번호입니다." << endl;
		}
	}
}
// Function :void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
 // Description: 구매물품등록을 하기 위한 곳으로 가는 함수입니다
 // Parameters :  Client currentUser - 현재 유저의 정보를 담은 클래스
 //               BidItemCollection BidItemCollect - 현재 존재하는 BidItemCollection
 //               SellItemCollection SellItemCollect - 현재 존재하는 SellitemCollection
 // Return Value : 없음
 // Created: 2016/6/18 16:20 pm
 // Author: 최민수
void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect) {
	string search;
	cout << "- 4.1. 경매 중인 물품 조회" << endl;
	cout << "# 경매 물품의 키워드를 입력하세요 : ";
	cin >> search;
	SellItemCollect.findSellList(currentUser, search, BidItemCollect);

	return;
}
// Function :void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect);
 // Description: 구매물품등록을 하기 위한 곳으로 가는 함수입니다
 // Parameters :  Client currentUser - 현재 유저의 정보를 담은 클래스
 //               BidItemCollection BidItemCollect - 현재 존재하는 BidItemCollection
 // Return Value : 없음
 // Created: 2016/6/18 23:20 pm
 // Author: 최민수
void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect) {
	string search;
	cout << "- 4.2. 참여 중인 물품 조회" << endl;
	BidItemCollect.getBidList(currentUser);

	return;
}
