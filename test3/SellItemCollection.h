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

	//������ �Ҹ���
	SellItemCollection(){}
	~SellItemCollection(){}

};


/*
//�Ǹ� �����ۿ� ���� �÷���
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


//������ �Ҹ���
SellItemCollection() {}
~SellItemCollection() { /*cout << "�Ҹ��ڰ� �����Ǿ����ϴ�." << endl; 

}; 

*/