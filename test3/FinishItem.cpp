#include "FinishItem.h"

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

