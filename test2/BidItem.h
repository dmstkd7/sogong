#pragma once
#include "Day.h"
#include "Item.h"


extern Day CurrentTime;

class BidItem : public Item {
protected:
	Day remainTime;
	int bidPrice;

public:
	BidItem() {}
	BidItem(string bname, Day bstartTime, Day bendTime, int btotalNum, int bstartPrice, string bownerID, int bitemID, int bbidPrice) {
		name = bname;
		startTime = bstartTime;
		endTime = bendTime;
		totalNum = btotalNum;
		startPrice = bstartPrice;
		ownerID = bownerID;
		itemID = bitemID;
		bidPrice = bbidPrice;
	}
	~BidItem() {
		//cout << "¼Ò¸êÀÚ" << endl;
	}
	Day getRemainTime();
	int getBidPrice();
	void setRemainTime();
};