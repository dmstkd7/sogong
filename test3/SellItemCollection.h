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

// Function : void SellItemCollection::addSellItem()
// Description: 물품등록을 하는 함수이다. 물품등록의 기본정보를 묻고 SellItemcollection에 그 값을 입력시킨다
// Parameters :   없다
// Return Value :  없다
//
// Created: 2016/6/15/ 19:23 pm
// Author: 장은상

	void addSellItem();
	
// Function : SellItem SellItemCollection::getSellItem(int i)
 // Description: SellItemCollection의 SellItem을 리턴 받는 함수이다
 //		 i에 대한 값을 넘기면 그 번호에 해당하는 SellItem을 리턴한다.
 // Parameters :   int i - SellItem[100]중 비어있는 값을 나타냄
 // Return Value :  원하는 번호에 해당하는 SellItem 리턴
 //
 // Created: 2016/6/15/ 18:20 pm
 // Author: 장은상

	
	SellItem getSellItem(int i);
	
// Function : void SellItemCollection::setSellItem(int wantChangeNum, SellItem newItem)
// Description: 바꾸고 싶은 번호와 셋팅하고 싶은 SellItem을 연결짓는 역할을 하는 함수이다
// Parameters :   int wantChangeNum, SellItem newItem
// Return Value :  없다
//
// Created: 2016/6/15/ 18:30 pm
// Author: 장은상
	
	void setSellItem(int i, SellItem newItem);

// Function : void SellItemCollection::getSellItemList()
// Description: SellItemCollection에 있는 SellItem에서 값이 들어있는 값을 출력하는 함수이다
//              판매중인 아이템 리스트 조회이다.
// Parameters :   없다
// Return Value :  없다
//
// Created: 2016/6/15/ 20:24 pm
// Author: 장은상

	void getSellItemList();

// Function : void SellItemCollection::findSellList(Client currentUser, string search, BidItemCollection BidItemCollect)
// Description: To make BidItem, Search SellItem
// Parameters :   
//	1. Client currentUser : Client who want to find item to make BidItem
//	2. string search : the value which mean Item's name which is wanted by Client
//	3. BidItemCollection BidItemCollect : the Collection of BidItems
// Return Value :  
//
// Created: 2016/6/18/ 21:20 pm
// Author: 최민수

	void findSellList(Client, string, BidItemCollection);

// Function : void SellItemCollection::getSellItem(Client currentUser, int num, int* sellList, BidItemCollection BidItemCollect)
// Description:  show the detail information of selected SellItem
// Parameters :   
//	1. Client currentUser : who want know detail information of selected SellItem
//	2. int num : number which mean selected number.
//	3. int* sellList : which have itemIDs in SellItemList
//	4. BidItemCollection BidItemCollect : Collection of BidItem
// Return Value :  
//
// Created: 2016/6/19/ 01:16 pm
// Author: 최민수

	void getSellItem(Client, int, int*, BidItemCollection);

	//생성자 소멸자
	SellItemCollection(){}
	~SellItemCollection(){}

};


