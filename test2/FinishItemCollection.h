#pragma once
#include "FinishItem.h"
#include "SellItem.h"
#include "SellItemCollection.h"
#include <vector>



class FinishItemCollection{
private:
	FinishItem finishItem[100];
public:

	FinishItem getFinishItem(int i);
	void getFinishItemList();
	void addFinishItem();
	void setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem);

	FinishItemCollection(){}
	~FinishItemCollection(){}
};