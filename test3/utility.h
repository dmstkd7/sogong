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