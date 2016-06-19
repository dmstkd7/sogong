#pragma once
#include "Day.h"
#include "Item.h"


extern Day CurrentTime;
// 현재시간에 관한 전역변수

// Class : BidItem
// Description: This is a BidItem class. 
//  ……………………………………….
//  ………………………………………
// Created: 2016/06/15 20:00 pm
// Author: 최민수
// mail: minsproject@naver.comr
//
// Revisions : 
//   1. When & Who : 2016/06/15 21:12 pm by 최민수
//      What : added remainTime
// 
// 

class BidItem : public Item {
protected:
	Day remainTime; // BidItem의 남은시간
	int bidPrice; // BidItem의 입찰가격

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
	~BidItem() {}
	
// Function : Day getRemainTime()
// Description: This is a function that calculates RemainTime.
// Parameters :  
// Return Value :  RemainTime value
//
// Created: 2016/06/15 22:01 pm
// Author: 최민수
// 
// Revisions : 
//
	Day getRemainTime();
	
// Function : int getBidPrice()
// Description: This is a function that get BidPrice.
// Parameters :  
// Return Value :  BidPrice
//
// Created: 2016/06/15 22:35 pm
// Author: 최민수
// 
// Revisions : 

	int getBidPrice();

// Function : void setRemainTime()
// Description: This is a function that set RemainTime.
// Parameters :  
// Return Value : 
//
// Created: 2016/06/15 23:12 pm
// Author: 최민수
// 
// Revisions : 

	void setRemainTime();
};
