#pragma once
#include "Item.h"
#include "Day.h"


class SellItem : public Item {
private:
	Day remainTime;

public:

	Day getRemainTime();
	void setRemainTime(Day remaintime);

	//기본생성자
	//SellItem(){ cout << "SellItem 생성자" << endl; }
	SellItem(){}

	//초기화 생성자 현황, 이름, 시작시간, 끝나는 시간, 남은 시간, 총 판매 수량, 시작 가격, 오너Id, 아이템 ID
	//남은시간은 현재 시간과 비교해야 됌
	SellItem(string i_name, Day i_startTime, Day i_endTime, Day i_remainTime, int i_totalNum, int i_startPrice, string i_ownerID, int i_itemID){
		name = i_name;
		startTime = i_startTime;
		endTime = i_endTime;
		totalNum = i_totalNum;
		startPrice = i_startPrice;
		ownerID = i_ownerID;
		itemID = i_itemID;
		bidPersonNum = 0;

	}
	//~SellItem(){ cout << "SellItem 소멸자" << endl; }
	~SellItem(){}
};