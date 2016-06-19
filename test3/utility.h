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


// Function : void querySellItem();
 // Description: 판매중인 것을 조회하는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:12 pm
 // Author: 장은상
void querySellItem();

// Function : void queryFinishItem();
 // Description: 판매가 완료된 것을 조회하는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:18 pm
 // Author: 장은상
void queryFinishItem();

// Function : void changeSession();
 // Description: CurrentUser의 Session을 바꿔주는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 //
 // Created: 2016/6/20 02:29 pm
 // Author: 장은상
void changeSession();


// Function : void managementRegisterItem();
 // Description: 판매물품등록을 하기 위한 곳으로 가는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 // Created: 2016/6/20 02:51 pm
 // Author: 장은상
void managementRegisterItem();


// Function : void setCurrentTime();
 // Description: 현재 시간을 바꿔주는 함수입니다
 // Parameters :  없음
 // Return Value : 없음
 // Created: 2016/6/20 03:11 pm
 // Author: 장은상
void setCurrentTime();


// Function : void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
 // Description: To show interface for searching SellItem for Bidding and managing BidItem
 // Parameters :  Client currentUser - Client who want to search SellItem or manage BidItems
 //               BidItemCollection BidItemCollect - Collection of BidItems
 //               SellItemCollection SellItemCollect - Collection of SellItems
 // Return Value : 없음
 // Created: 2016/6/16 02:11 am
 // Author: 최민수
void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);


// Function :void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
// Description: To show interface for searching SellItem for Bidding
// Parameters :  Client currentUser - Client who want to search SellItem or manage BidItems
//               BidItemCollection BidItemCollect - Collection of BidItems
//               SellItemCollection SellItemCollect - Collection of SellItems // Return Value : 없음
// Created: 2016/6/16 09:20 am
// Author: 최민수
void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);


// Function :void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect);
// Description: To show interface for managing BidItem
// Parameters :  Client currentUser - Client who want to search SellItem or manage BidItems
//               BidItemCollection BidItemCollect - Collection of BidItems
// Return Value : 없음
// Created: 2016/6/16 09:45 pm
// Author: 최민수
void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect);
