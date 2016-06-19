#include "BidItem.h"

Day BidItem::getRemainTime() {
	
	//이거는 나중에 다시 한번 생각해보는 기회를 갖자
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
	return remainTime;
}

void BidItem::setRemainTime(){
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
}


int BidItem::getBidPrice() {
	return bidPrice;
}