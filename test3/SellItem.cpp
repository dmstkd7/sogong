#pragma once
#include "SellItem.h"

extern Day CurrentTime;

// Function : Day getRemainTime();
	 // Description: remainTime을 리턴하는 함수입니다…
	 // Parameters :  없음
	 // Return Value :  Day타입 return
	 // Created: 2016/6/18 20:40 pm
	 // Author: 장은상

Day SellItem::getRemainTime(){
	//SellItem에 remainTime이 의미가 없는것 같은데?
	//의문점을 꼭 해결하시오
	//대문자 소문자 이거도 꼭맞추시오
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
	return remainTime;
}
