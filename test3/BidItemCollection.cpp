#include "BidItemCollection.h"

// Function : ostream& operator<<(ostream& os, Day tmpTime)
// Description: This is a function that print Day.
// Parameters :  
// Return Value : 
//
// Created: 2016/06/19 14:01 pm
// Author: 최민수
// 
// Revisions : 
//

ostream& operator<< (ostream& os, Day tmpTime) {
	os << tmpTime.year << "/" << tmpTime.month << "/" << tmpTime.day << " " << tmpTime.hour << ":00";
	return os;
}

extern BidItemCollection BidItemCollect;
// BidItemCollection의 전역변수

// Function : int BidItemCollection::getNumberBid(int chk)
// Description: This is a function that get the number of BidItem which itemID is chk.
// Parameters :  
//	int chk : item's itemID for checking value
// Return Value : the number of BidItem which itemID is chk. 
//	
// Created: 2016/06/16 10:01 am
// Author: 최민수
// 
// Revisions : 
//

int BidItemCollection::getNumberBid(int chk) {
	int num = 0;
	cout << "번호 : " << chk << endl;
	for (int i = 0; i < 100; i++) {
		if (chk == totalBidItem[i].getItemID()) { num++; }
	} // 반복문으로 collection을 fullscan 하여서 특정 아이템의 입찰 갯수를 구한다.

	return num;
}

// Function : void BidItemCollection::getBidList(Client currentClient)
// Description: This is a function that print the list of user's BidItem.
// Parameters :  
//	Client currentClient : Client who want to print the list of his/her BidItem.
// Return Value :  
//	
// Created: 2016/06/16 10:01 am
// Author: 최민수
// 
// Revisions : 
//

void BidItemCollection::getBidList(Client currentClient) {
	int tCollection[100];
	int chk = 0;
	int input;
	int num = 1;

	for (int i = 0; i < 100; i++) {
		if (currentClient.getId() == totalBidItem[i].getOwnerID()) {
			tCollection[chk] = totalBidItem[i].getItemID();
			cout << "번호	" << "이름	" << "남은시간	" << "시작가격	" << endl;
			cout << num << "	" << totalBidItem[i].getName() << "	";
			cout << totalBidItem[i].getRemainTime() << "	" << totalBidItem[i].getStartPrice() << endl;
			chk++;
			num++;
		} // 현재 사용중인 클라이언트의 ID을 통해서 속하여 있는 아이템을 출력한다.
	}

	while (1){
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "*입력선택 : ";
		cin >> input;
		cin.clear();
		cin.ignore(256, '\n');
		if (input == 0) {
			break;
		}
		else if (input > chk || input < 0) {
			cout << "알맞이 않은 입력값입니다." << endl;
			continue;
		}
		else {
			getBidItem(input - 1, tCollection);
			break;
		}
	}

	return;
}

// Function : void BidItemCollection::setBidItem(int i, BidItem bid)
// Description: This is a function that set user's BidItem.
// Parameters :  
//	int i : number which means place where BidItem will to be in
//	BidItem bid : BidItem which will be in BidItemCollection
// Return Value :  
//	
// Created: 2016/06/16 16:26 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/17 13:12 pm by 최민수
//      What : added setRemainTime() ;
//

void BidItemCollection::setBidItem(int i, BidItem bid) {
	totalBidItem[i] = bid;
	totalBidItem[i].setRemainTime(); // 입찰한 시간의 값을 가지고 남은 시간을 계산한다.
}

// Function : void BidItemCollection::getBidItem(int num, int* bidList)
// Description: This is a function that get choosen user's BidItem.
// Parameters :  
//	int num : selected number in getBidList operation
//	int* bidList : itemID list from getBidList operation's List
// Return Value :  
//	
// Created: 2016/06/16 18:34 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/18 11:18 am by 최민수
//      What : add while() to make loop ;
//

void BidItemCollection::getBidItem(int num, int* bidList) {
	int chk = bidList[num];
	int i = 0;
	int input = 0;

	cout << "- 4.2." << num << ". 선택된 물품의 상세조회" << endl;
	while (chk != totalBidItem[i].getItemID()) { i++; } // itemID을 통해서 상세히 보고자 하는 아이템을 찾는다.

	cout << "번호	" << "물품명	" << "수량	" << "시작가격	" << "입찰금액	" << "경매 시작시간	" << "경매 종료시간	" << "남은시간	" << endl;
	cout << num << " ";
	cout << totalBidItem[i].getName() << "	";
	cout << totalBidItem[i].getTotalNum() << "	";
	cout << totalBidItem[i].getStartPrice() << "	";
	cout << totalBidItem[i].getBidPrice() << "	";
	cout << totalBidItem[i].getStartTime() << "	";
	cout << totalBidItem[i].getEndTime() << "	";
	cout << totalBidItem[i].getRemainTime() << endl;
	
	while(1){ // 각 경우에 대한 입력과 결과에 대한 반복문
		cout << "0. 메인메뉴로 돌아가기" << endl ;
		cin >> input ;
		cin.clear() ;
		cin.ignore(256, '\n') ;
		if (input == 0) {
			return;
		}
		else{
			cout << "알맞지 않은 입력값입니다." << endl ; // 0번 이외는 다 알맞지 않은 값이다.
		}
	}
	return;
}

// Function : void BidItemCollection::addBidItem(Client currentClient, SellItem bid)
// Description: This is a function that add BidItem.
// Parameters :  
//	Client currentClient : Client who want to add BidItem
//	SellItem bid : SellItem which is to be BidItem
// Return Value :  
//	
// Created: 2016/06/16 19:54 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/18 11:18 am by 최민수
//      What : add while() to make loop ;
//	2. When & Who : 2016/06/18 11:32 am by 최민수
//      What : modify if / else if / if in while loop;
//	3. When & Who : 2016/06/19 12:11 am by 최민수
//      What : add cin.clear(), cin.ignore(256,'\n') ;
//

void BidItemCollection::addBidItem(Client currentClient, SellItem bid) {
	string tname = bid.getName();
	Day tstartTime = bid.getStartTime();
	Day tendTime = bid.getEndTime();
	int ttotalNum = bid.getTotalNum();
	int tstartPrice = bid.getStartPrice();
	string townerID = currentClient.getId();
	int titemID = bid.getItemID();
	Day tremainTime = bid.getRemainTime();
	int tbidPrice;
	// bid라는 입찰하고자 하는 SellItem의 정보를 가져온다.
	char chk;
	int i = 0;

	while (1){ // 입력부터 입찰완료까지 진행한다.
		cout << "# 입찰 금액을 입력하십시오 : ";
		cin >> tbidPrice;
		cin.clear();
		cin.ignore(256, '\n');
		if (tbidPrice<0) {
			cout << "입찰 금액이 0보다 적습니다." << endl;
			continue;
		}
		else if (tbidPrice < bid.getStartPrice()){
			cout << "입찰 금액이 입찰 시작 금액보다 적습니다." << endl;
			continue;
		}
		else if (tbidPrice >= bid.getStartPrice()){ }
		else{
			cout << "알맞지 않은 입력값입니다. 메인메뉴로 돌아갑니다." << endl;
			return;
		}
		cout << "정말 입찰하시겠습니까? (Y/N) : ";
		cin >> chk;
		cin.clear();
		cin.ignore(256, '\n');
		if (chk == 'N') {
			cout << "입찰이 취소되었습니다. 메인메뉴로 돌아갑니다." << endl;
			return;
		}
		else if (chk == 'Y') {
			while (totalBidItem[i].getName() != "") { cout << totalBidItem[i].getName() << endl; i++; }
			BidItem tmpBid(tname, tstartTime, tendTime, ttotalNum, tstartPrice, townerID, titemID, tbidPrice);
			BidItemCollect.setBidItem(i, tmpBid);
			cout << "입찰이 완료되었습니다." << endl;
			return;
		}
		else {
			cout << "알맞지 않은 입력값입니다. 메인메뉴로 돌아갑니다." << endl;
			return;
		}
	}

}
