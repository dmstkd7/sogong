#include "BidItem.h"

Day BidItem::getRemainTime() {
	
	//�̰Ŵ� ���߿� �ٽ� �ѹ� �����غ��� ��ȸ�� ����
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