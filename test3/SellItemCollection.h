#pragma once
#include "Client.h"
#include "SellItem.h"
#include <string>
#include <iostream>
using namespace std;



class SellItemCollection{
private:
	SellItem totalSellItem[100];
public:

	void addSellItem();
	SellItem getSellItem(int i);
	void setSellItem(int i, SellItem newItem);
	//void deleteSellItem(SellItem *removeSell);
	void getSellItemList();

	void findSellList(Client, string, BidItemCollection);
	void getSellItem(Client, int, int*, BidItemCollection);

	//생성자 소멸자
	SellItemCollection(){}
	~SellItemCollection(){}

};


/*
//판매 아이템에 대한 컬렉션
class SellItemCollection {
private:
SellItem totalSellItem[100];
public:
void addSellItem();
SellItem getSellItem(int i);
void setSellItem(int i, SellItem newItem);
void getSellItemList();
void findSellList(Client, string, BidItemCollection);
void getSellItem(Client, int, int*, BidItemCollection);


//생성자 소멸자
SellItemCollection() {}
~SellItemCollection() { /*cout << "소멸자가 생성되었습니다." << endl; 

}; 

*/