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
	����ü �� �ȵǴ� �ɱ� ���߿� �����
	int getTotalSoldNumber();
	int getBidderNumber();
	void setTotalSoldNumber(int i_totalSoldNumber);
	void setBidderNumber(int i_bidderNumer);
	*/
	//��� set�� �־�� �ϳ� ����� �����Ǿ �ȵǴ°ǵ�?

	FinishItem(){};
	~FinishItem(){}

};