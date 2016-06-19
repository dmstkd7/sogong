#pragma once
#include "BidItem.h"
#include "SellItem.h"
#include "Client.h"
#include <string>
#include <iostream>
using namespace std;


ostream& operator<< (ostream& os, Day tmpTime);
// Day를 출력하기 위한 연산자 오버로딩 선언

//구매 아이템에 대한 컬렉션
// Class : BidItemCollection
// Description: This is Collection of BidItems. 
//  ……………………………………….
//  ………………………………………
// Created: 2016/06/16 01:10 pm
// Author: 최민수
// mail: minsproject@naver.com
//
// Revisions : 
//   1. When & Who : 2016/06/16 01:42 pm by 최민수
//      What : added setBidItem
// 
// 

class BidItemCollection {
private:
	BidItem totalBidItem[100]; // BidItem's array set
public:

// Function : void BidItemCollection::setBidItem(int i, BidItem bid)
// Description: This is a function that set user's BidItem.
// Parameters :  
//	int i : number which means place where BidItem will to be in
//	BidItem bid : BidItem which will be in BidItemCollection
// Return Value :  
//	
// Created: 2016/06/16 16:26 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/17 13:12 pm by 최민수
//      What : added setRemainTime() ;
//

	void setBidItem(int, BidItem);

// Function : void BidItemCollection::getBidItem(int num, int* bidList)
// Description: This is a function that get choosen user's BidItem.
// Parameters :  
//	int num : selected number in getBidList operation
//	int* bidList : itemID list from getBidList operation's List
// Return Value :  
//	
// Created: 2016/06/16 18:34 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/18 11:18 am by 최민수
//      What : add while() to make loop ;
//

	void getBidItem(int, int*);

// Function : void BidItemCollection::getBidList(Client currentClient)
// Description: This is a function that print the list of user's BidItem.
// Parameters :  
//	Client currentClient : Client who want to print the list of his/her BidItem.
// Return Value :  
//	
// Created: 2016/06/16 10:01 am
// Author: 최민수
// 
// Revisions : 
//

	void getBidList(Client);

// Function : void BidItemCollection::addBidItem(Client currentClient, SellItem bid)
// Description: This is a function that add BidItem.
// Parameters :  
//	Client currentClient : Client who want to add BidItem
//	SellItem bid : SellItem which is to be BidItem
// Return Value :  
//	
// Created: 2016/06/16 19:54 pm
// Author: 최민수
// 
// Revisions : 
//	1. When & Who : 2016/06/18 11:18 am by 최민수
//      What : add while() to make loop ;
//	2. When & Who : 2016/06/18 11:32 am by 최민수
//      What : modify if / else if / if in while loop;
//	3. When & Who : 2016/06/19 12:11 am by 최민수
//      What : add cin.clear(), cin.ignore(256,'\n') ;
//

	void addBidItem(Client, SellItem);

// Function : int BidItemCollection::getNumberBid(int chk)
// Description: This is a function that get the number of BidItem which itemID is chk.
// Parameters :  
//	int chk : item's itemID for checking value
// Return Value : the number of BidItem which itemID is chk. 
//	
// Created: 2016/06/16 10:01 am
// Author: 최민수
// 
// Revisions : 
//

	int getNumberBid(int);

	BidItemCollection() {} // BIdItemCollection 생성자
	~BidItemCollection() {} // BIdItemCollection 소멸자
};

