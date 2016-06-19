#pragma once
#include "Item.h"



class FinishItem : public Item  {
private:
	int totalSoldNumber;
	int bidderNumber;

public:

	int FinishItem::getTotalSoldNumber(){ return totalSoldNumber; }
	int FinishItem::getBidderNumber(){ return bidderNumber; }
	void FinishItem::setTotalSoldNumber(int i_totalSoldNumber){ totalSoldNumber = i_totalSoldNumber; }
	void FinishItem::setBidderNumber(int i_bidderNumer){ bidderNumber = i_bidderNumer; }

	/*
	도대체 왜 안되는 걸까 나중에 물어보자
	int getTotalSoldNumber();
	int getBidderNumber();
	void setTotalSoldNumber(int i_totalSoldNumber);
	void setBidderNumber(int i_bidderNumer);
	*/
	//얘는 set이 있어야 하나 절대로 수정되어선 안되는건데?

	FinishItem(){};
	~FinishItem(){}

};