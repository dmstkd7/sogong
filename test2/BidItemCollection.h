#pragma once
#include "BidItem.h"
#include "SellItem.h"
#include "Client.h"
#include <string>
#include <iostream>
using namespace std;




//구매 아이템에 대한 컬렉션
class BidItemCollection {
private:
	BidItem totalBidItem[100];
public:
	void setBidItem(int, BidItem);
	void getBidItem(int, int*);
	void getBidList(Client);
	void addBidItem(Client, SellItem);

	int getNumberBid(int);

	BidItemCollection() {} // BIdItemCollection 생성자를 어떻게?? BidItem 생성자가 없다는데? default 값을 줘야하나 생성자에??
	~BidItemCollection() {}
};

