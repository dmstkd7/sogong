#pragma once
#include "SellItem.h"

extern Day CurrentTime;

Day SellItem::getRemainTime(){
	//SellItem�� remainTime�� �ǹ̰� ���°� ������?
	//�ǹ����� �� �ذ��Ͻÿ�
	//�빮�� �ҹ��� �̰ŵ� �����߽ÿ�
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
	return remainTime;
}