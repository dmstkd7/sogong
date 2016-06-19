#include "BidItem.h"

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

Day BidItem::getRemainTime() {
	
	//이거는 나중에 다시 한번 생각해보는 기회를 갖자
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
	return remainTime;
}
// Function : int getBidPrice()
// Description: This is a function that get BidPrice.
// Parameters :  
// Return Value :  BidPrice
//
// Created: 2016/06/15 22:35 pm
// Author: 최민수
// 
// Revisions : 

void BidItem::setRemainTime(){
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
}

// Function : void setRemainTime()
// Description: This is a function that set RemainTime.
// Parameters :  
// Return Value : 
//
// Created: 2016/06/15 23:12 pm
// Author: 최민수
// 
// Revisions : 

int BidItem::getBidPrice() {
	return bidPrice;
}
