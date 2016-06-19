// Class : utility.h
 // Description: 메인에서 쓸 함수를 한 데 모아둔 것입니다
 // Created: 2016/6/20 02:11 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 22016/6/20 02:11 pm 02:30 pm by EunsangJang
 //      What : 팀원과 합치는 과정에서 queryBidItem, queryMyBidItem, managemnetRegisterItem()등을 추가하였습니다


#pragma once
#include "Client.h"
#include "BidItemCollection.h"
#include "FinishItemCollection.h"
#include <iostream>
#include "Day.h"
using namespace std;

void querySellItem();
void queryFinishItem();
void changeSession();
void managementRegisterItem();
void setCurrentTime();
void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect);
