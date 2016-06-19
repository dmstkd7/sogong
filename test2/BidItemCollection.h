#pragma once
#include "BidItem.h"
#include "SellItem.h"
#include "Client.h"
#include <string>
#include <iostream>
using namespace std;




//���� �����ۿ� ���� �÷���
class BidItemCollection {
private:
	BidItem totalBidItem[100];
public:
	void setBidItem(int, BidItem);
	void getBidItem(int, int*);
	void getBidList(Client);
	void addBidItem(Client, SellItem);

	int getNumberBid(int);

	BidItemCollection() {} // BIdItemCollection �����ڸ� ���?? BidItem �����ڰ� ���ٴµ�? default ���� ����ϳ� �����ڿ�??
	~BidItemCollection() {}
};

