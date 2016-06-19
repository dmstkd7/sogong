// Class : SellItem.h
 // Description: 판매중인 아이템을 구현한 코드입니다
 //  ……………………………………….
 //  ………………………………………
 // Created: 2016/6/18 12:30 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 2016/6/18 21:30 pm pm by Eunsang-Jang
 //      한것은 : 기본 생성자 수정 
 
#pragma once
#include "Item.h"
#include "Day.h"

class SellItem : public Item {
private:
	Day remainTime;
public:

	// Function : Day getRemainTime();
	 // Description: remainTime을 리턴하는 함수입니다…
	 // Parameters :  없음
	 // Return Value :  Day타입 return
	 // Created: 2016/6/18 20:40 pm
	 // Author: 장은상
	Day getRemainTime();
	// Function : void setRemainTime();
	 // Description: remainTime을 리턴하는 함수입니다…
	 // Parameters :  없음
	 // Return Value :  없음
	 // Created: 2016/6/18 20:40 pm
	 // Author: 장은상
	void setRemainTime(Day remaintime);


	SellItem(){}
	//초기화 생성자 현황, 이름, 시작시간, 끝나는 시간, 남은 시간, 총 판매 수량, 시작 가격, 오너Id, 아이템 ID
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
	~SellItem(){}
};
