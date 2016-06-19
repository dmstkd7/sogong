// Class : SellItemCollection.cpp
 // Description:SellItemCollection class를 구현한 코드입니다.
 //  ……………………………………….
 //  ………………………………………
 // Created: 2016/6/14 23:00 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 2016/6/15 22:00 pm 23:30 pm by Jang-eunsang
 //      What : added bFlag, 
 //            modified calCosts
 //              …..


#include "SellItemCollection.h"
#include "BidItemCollection.h"
#include "Client.h"
#include <vector>

//외부 전역변수 CurrentUser,CurrentTime을 가져온다
extern Client CurrentUser;
extern Day CurrentTime;

// Function : operator<<
 // Description: Day에 대한 시간을 예쁘게 출력해주는 함수이다
 // Parameters :   없음
 // Return Value :  ostream
 // Created: 
 // Author: 최민수
ostream& operator<< (ostream& os, Day tmpTime);


// Function : SellItem SellItemCollection::getSellItem(int i)
 // Description: SellItemCollection의 SellItem을 리턴 받는 함수이다
 //		 i에 대한 값을 넘기면 그 번호에 해당하는 SellItem을 리턴한다.
 // Parameters :   int i - SellItem[100]중 비어있는 값을 나타냄
 // Return Value :  원하는 번호에 해당하는 SellItem 리턴
 //
 // Created: 2016
 // Author: Gildong Hong
 // 
 // Revsions : 
 //   1. When & Who : 2007/05/16 13:12 pm by Ji-sung Park
 //      What : added other factors when calculating costs…
 //              …..
 //   2. ……….      
SellItem SellItemCollection::getSellItem(int i){
	return totalSellItem[i];
}

//totalSellItem에서 wantChange번호를 newItem을 추가 시키는 함수입니다.
void SellItemCollection::setSellItem(int wantChangeNum, SellItem newItem){
	totalSellItem[wantChangeNum] = newItem;
}


void SellItemCollection::addSellItem(){

	cout << "************** 물품 등록을 하러 오셨군요 반갑습니다 **************" << endl;


	string name, ownerID;
	name = CurrentUser.getName();
	ownerID = CurrentUser.getId();
	int totalNum, startPrice;
	Day startTime, endTime, remainTime;
	while (1){
		try{
			cout << "물품명을 입력하세요 : ";
			cin >> name;
			cin.clear();
			cin.ignore(256, '\n');
			if (name.length() < 2) throw 1;
			cout << "총판매수량을 입력하세요 : ";
			cin >> totalNum;
			cin.clear();
			cin.ignore(256, '\n');
			if (totalNum< 0) throw 2;
			cout << "시작 가격을 입력하세요 : ";
			cin >> startPrice;
			cin.clear();
			cin.ignore(256, '\n');
			if (startPrice< 0) throw 3;
			cout << "경매 시작시간을 입력하세요 년 : ";
			cin >> startTime.year;
			cin.clear();
			cin.ignore(256, '\n');
			if (startTime.year < CurrentTime.year) throw 4;
			cout << "경매 시작시간을 입력하세요 월 : ";
			cin >> startTime.month;
			cin.clear();
			cin.ignore(256, '\n');
			if ((startTime.year == CurrentTime.year) && startTime.month < CurrentTime.month) throw 4;
			if (startTime.month > 12 || startTime.month < 1) throw 6;
			cout << "경매 시작시간을 입력하세요 일 : ";
			cin >> startTime.day;
			cin.clear();
			cin.ignore(256, '\n');
			if ((startTime.year == CurrentTime.year) && (startTime.month == CurrentTime.month) && startTime.day < CurrentTime.day) throw 4;
			if (startTime.day > 31 || startTime.day < 1) throw 6;
			cout << "경매 시작시간을 입력하세요 시간 : ";
			cin >> startTime.hour;
			cin.clear();
			cin.ignore(256, '\n');
			if ((startTime.year == CurrentTime.year) && (startTime.month == CurrentTime.month) && (startTime.day == CurrentTime.day) && startTime.hour < CurrentTime.hour) throw 4;
			if (startTime.hour >= 24 || startTime.hour < 0) throw 6;

			

			cout << "경매 종료시간을 입력하세요 년 :";
			cin >> endTime.year;
			cin.clear();
			cin.ignore(256, '\n');
			//if (endTime.year < CurrentTime.year) throw 4;
			if (endTime.year < startTime.year) throw 5;
			cout << "경매 종료시간을 입력하세요 월 : ";
			cin >> endTime.month;
			cin.clear();
			cin.ignore(256, '\n');
			//if ((endTime.year == CurrentTime.year) && endTime.month < CurrentTime.month) throw 4;
			if ((endTime.year == startTime.year) && endTime.month < startTime.month) throw 5;
			if (endTime.month > 12 || endTime.month < 1) throw 6;
			cout << "경매 종료시간을 입력하세요 일 : ";
			cin >> endTime.day;
			cin.clear();
			cin.ignore(256, '\n');
			//if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && endTime.day < CurrentTime.day) throw 4;
			if ((endTime.year == startTime.year) && (endTime.month == startTime.month) && endTime.day < startTime.day) throw 5;
			if (endTime.day > 31 || endTime.day < 1) throw 6;
			cout << "경매 종료시간을 입력하세요 시간 : ";
			cin >> endTime.hour;
			cin.clear();
			cin.ignore(256, '\n');
			//if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && (endTime.day == CurrentTime.day) && endTime.hour < CurrentTime.hour) throw 4;
			if ((endTime.year == startTime.year) && (endTime.month == startTime.month) && (endTime.day == startTime.day) && endTime.hour < startTime.hour) throw 5;
			if (endTime.hour >= 24 || endTime.hour < 0) throw 6;

			remainTime.year = endTime.year - CurrentTime.year;
			remainTime.month = endTime.month - CurrentTime.month;
			remainTime.day = endTime.day - CurrentTime.day;
			remainTime.hour = endTime.hour - CurrentTime.hour;
			break;
		}
		catch (int type){
			switch (type){
			case 1:
				cout << "물품명을 적어도 2글자 이상 적어주세요" << endl;
				break;
			case 2:
				cout << "총 판매수량을 0원 이상으로 적어주세요" << endl;
				break;
			case 3:
				cout << "시작가격을 0원 이상으로 적어주세요" << endl;
				break;
			case 4:
				cout << "현재시간보다 더 적게 설정할 수는 없습니다." << endl;
				break;
			case 5:
				cout << "마감시간이 시작시간보다 전일 수는 없습니다" << endl;
				break;
			case 6:
				cout << "범위에 맞지 않는 수 입니다." << endl;
			}
			cout << "다시 입력하세요 " << endl;
			continue;
		}
	}

	SellItem newItem(name, startTime, endTime, remainTime, totalNum, startPrice, ownerID, Item::markItemID++);

	SellItem item;
	for (int i = 0; i < 100; i++){
		item = getSellItem(i);
		if (item.getName() == ""){
			setSellItem(i, newItem);
			break;
		}

	}
	cout << "\n" << "메뉴 등록이 완료되었습니다" << endl;

	return;
}

void SellItemCollection::getSellItemList(){

	int number = 1;
	//출력되는 번호와 ItemId를 연결하기 위한 변수
	vector< pair<int, SellItem>> tmp;
	int command = 0;


	//이것을 하는 이유는 출력되는 번호와 ItemID를 일치 시키기 위해 쓰레기값을 넣어두는 것이다
	SellItem trash;
	tmp.push_back(make_pair(0, trash));

	try{
		cout << "번호" << "   " << "물 품 명" << "   " << "총 판매수량" << "     " << "시작 가격" << endl;
		SellItem Item;
		for (int i = 0; i < 100; i++){
			Item = getSellItem(i);
			if (Item.getName() != ""){
				tmp.push_back(make_pair(Item.getItemID(), Item));
				cout << number++ << "        " << Item.getName() << "        " << Item.getTotalNum() << "             " << Item.getStartPrice() << endl;
			}
		}
		cout << "0. 메인 메뉴로 돌아가기" << endl;



		//상세보기를 할건지 안할건지 결정하는 곳입니다
		cout << "입력선택 : ";
		cin >> command;
		cin.clear();
		cin.ignore(256, '\n');
		if (command == 0) return;
		if (command >= number) throw 1;


		if (command != 0){
			//어떤 번호를 말하는건지 잘 모르겠다 일단 아이템 아이디로 넘겨보겠다
			cout << "번호" << "  " << "물 품 명" << "   " << "총 판매수량" << "   " << "시작 가격" << "   " << "입찰자 수" << "        " << "경매마감시간" << endl;
			cout << tmp[command].first << "      " << tmp[command].second.getName() << "         " << tmp[command].second.getTotalNum()
				<< "           " << tmp[command].second.getStartPrice() << "        " << tmp[command].second.getBidPersonNum() << "        "
				<< tmp[command].second.getEndTime().year << "년 " << tmp[command].second.getEndTime().month << "월 "
				<< tmp[command].second.getEndTime().day << "일 " << tmp[command].second.getEndTime().hour << "시간 "
				<< endl;
		}
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "입력선택 : ";
		cin >> command;
		cin.clear();
		cin.ignore(256, '\n');
		if (command != 0) throw 2;


	}
	catch (int type){
		if (type == 1){
			cout << "없는 상세보기를 입력하셨습니다 나가겠습니다\n" << endl;
			return;
		}

		else if (type == 2){
			cout << "입력이 0 말고는 더이상 할게 없습니다 나가겠습니다\n" << endl;
		}

	}
	return;
}


void SellItemCollection::findSellList(Client currentUser, string search, BidItemCollection BidItemCollect) {
	int tCollection[100];
	int chk = 0;
	int input;
	int num = 1;

	for (int i = 0; i < 100; i++) {
		if (search == totalSellItem[i].getName()) {
			tCollection[chk] = totalSellItem[i].getItemID();
			cout << "번호	" << "이름	" << "남은시간	" << "가격	" << endl;
			cout << num << "	" << totalSellItem[i].getName() << "	";
			cout << totalSellItem[i].getRemainTime() << "	" << totalSellItem[i].getStartPrice() << endl;
			num++;
			chk++;
		}
	}

	if (chk == 0) { cout << "찾는 물품이 없습니다. 메인 메뉴로 돌아갑니다." << endl; return; }
	while (1){
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "* 입력선택 : ";
		cin >> input;
		cin.clear();
		cin.ignore(256, '\n');
		if (input == 0) {
			break;
		}
		else if (input > chk || input < 0) {
			cout << "알맞지 않은 값입니다" << endl;
		}
		else {
			input--;
			getSellItem(currentUser, input, tCollection, BidItemCollect);
			break;
		}
	}

	return;

}


void SellItemCollection::getSellItem(Client currentUser, int num, int* sellList, BidItemCollection BidItemCollect) {
	int chk = sellList[num];
	int i = 0;
	int input;

	cout << "-4.1.1." << num << " 선택된 물품의 상세 조회" << endl;

	while (chk != totalSellItem[i].getItemID()) { i++; }
	cout << totalSellItem[i].getName() << " ";
	cout << totalSellItem[i].getStartTime() << " ";
	cout << totalSellItem[i].getEndTime() << " ";
	cout << totalSellItem[i].getTotalNum() << " ";
	cout << totalSellItem[i].getStartPrice() << " ";
	cout << totalSellItem[i].getOwnerID() << " ";
	cout << totalSellItem[i].getItemID() << " ";
	cout << totalSellItem[i].getRemainTime() << endl;

	while (1) {
		cout << "1. 입찰참여" << endl;
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "* 입력선택 : ";
		cin >> input;
		cin.clear();
		cin.ignore(256, '\n');
		if (input == 1) {
			BidItemCollect.addBidItem(currentUser, totalSellItem[i]);
			break;
		}
		else if (input == 0) { break; }
		else {
			cout << "알맞지 않은 값입니다." << endl;
			continue;
		}
	}
	return;
}
