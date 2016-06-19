// Class : FinishItem.h
 // Description: 판매종료된 아이템을 구현한 코드입니다
 //  ……………………………………….
 //  ………………………………………
 // Created: 2016/6/18 23:12 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 2016/06/20 1:36 pm by eunsang-Jang
 //      What : FinishItem.cpp을 읽지 못하는 치명적 오류 발생으로 인한 수정
 //            cpp을 여전히 읽지 못해 임시방편으로 cpp에서 구현해야 할것을 여기에 구현하였다
 //              …..
 //   2. When & Who : 2016/06/20 2:00 pm by eunsang-Jang
 //      What : 고치려고 이것저것 수정하였으나 아직도 되지 않았다. 바뀐 것이 없다
 //              …..      

#pragma once
#include "Item.h"

class FinishItem : public Item  {
private:
	int totalSoldNumber;
	int bidderNumber;

public:
	// Function : int FinishItem::getTotalSoldNumber()
	 // Description: totalSoldNumber를 리턴하는 기본함수이다
	 // Parameters :  없음
	 // Return Value :  totalSolNumber return받는다
	 // Created: 2016/6/19 21:22 pm
	 // Author: 장은상
	int FinishItem::getTotalSoldNumber(){ return totalSoldNumber; }
	
	// Function : int FinishItem::getBidderNumber()
	 // Description: bidderNumber 리턴하는 기본함수이다
	 // Parameters :   없음
	 // Return Value : bidderNumber 
	 // Created: 2016/6/19 21:22 pm
	 // Author: 장은상
	int FinishItem::getBidderNumber(){ return bidderNumber; }
	
	
	// Function : 	void FinishItem::setTotalSoldNumber(int i_totalSoldNumber)
	 // Description: totalSoldNumber 설정해주는 함수이다
	 // Parameters :   int i_totalSoldNumber - totalSolnumber를 어떤 값으로 설정할지 정해주는 파라미터다
	 // Return Value : 없다
	 // Created: 2016/6/19 21:23 pm
	 // Author: 장은상
	void FinishItem::setTotalSoldNumber(int i_totalSoldNumber){ totalSoldNumber = i_totalSoldNumber; }
	
	
	// Function : 	 void FinishItem::setBidderNumber(int i_bidderNumer)
	 // Description: BidderNumber를 설정해주는 함수이다
	 // Parameters :   int i_bidderNumer - bidderNumer 어떤 값으로 설정할지 정해주는 파라미터다
	 // Return Value : 없다
	 // Created: 2016/6/19 21:23 pm
	 // Author: 장은상
	void FinishItem::setBidderNumber(int i_bidderNumer){ bidderNumber = i_bidderNumer; }
	

	FinishItem(){}
	~FinishItem(){}

};
