#include "BidItemCollection.h"

ostream& operator<< (ostream& os, Day tmpTime) {
	os << tmpTime.year << "/" << tmpTime.month << "/" << tmpTime.day << " " << tmpTime.hour << ":00";
	return os;
}

extern BidItemCollection BidItemCollect;

int BidItemCollection::getNumberBid(int chk) {
	int num = 0;
	cout << "번호 : " << chk << endl;
	for (int i = 0; i < 100; i++) {
		if (chk == totalBidItem[i].getItemID()) { num++; }
	}

	return num;
}

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
		}
	}

	cout << "0. 메인 메뉴로 돌아가기" << endl;
	cout << "*입력선택 : ";
	cin >> input;
	if (input == 0) {
		return;
	}
	else {
		getBidItem(input - 1, tCollection);
	}

	return;
}

void BidItemCollection::setBidItem(int i, BidItem bid) {
	totalBidItem[i] = bid;
	totalBidItem[i].setRemainTime();
	cout << "출력한 내용 : " << totalBidItem[i].getStartTime() << " " << totalBidItem[i].getRemainTime() << " " << totalBidItem[i].getName() << endl;
}

void BidItemCollection::getBidItem(int num, int* bidList) {
	int chk = bidList[num];
	int i = 0;
	int input = 0;

	cout << "- 4.2." << num << ". 선택된 물품의 상세조회" << endl;
	while (chk != totalBidItem[i].getItemID()) { i++; }

	cout << "번호	" << "물품명	" << "수량	" << "시작가격	" << "입찰금액	" << "경매 시작시간	" << "경매 종료시간	" << "남은시간	" << endl;
	cout << num << " ";
	cout << totalBidItem[i].getName() << "	";
	cout << totalBidItem[i].getTotalNum() << "	";
	cout << totalBidItem[i].getStartPrice() << "	";
	cout << totalBidItem[i].getBidPrice() << "	";
	cout << totalBidItem[i].getStartTime() << "	";
	cout << totalBidItem[i].getEndTime() << "	";
	cout << totalBidItem[i].getRemainTime() << endl;
	if (input == 0) {
		return;
	}

	return;
}

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

	char chk;
	int i = 0;

	cout << "# 입찰 금액을 입력하십시오 : ";
	cin >> tbidPrice;
	cout << "정말 입찰하시겠습니까? (Y/N) : ";
	cin >> chk;

	if (chk == 'Y') {
		while (totalBidItem[i].getName() != "") { cout << totalBidItem[i].getName() << endl; i++; }
		BidItem tmpBid(tname, tstartTime, tendTime, ttotalNum, tstartPrice, townerID, titemID, tbidPrice);
		BidItemCollect.setBidItem(i, tmpBid);
	}

	return;
}