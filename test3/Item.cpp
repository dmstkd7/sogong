#include "Item.h"
using namespace std;

/////////// class Item ±¸Çö /////////////////
int Item::getItemID(){
	return itemID;
}
Day Item::getStartTime(){ return startTime; }
Day Item::getEndTime(){ return endTime; }

int Item::getTotalNum(){ return totalNum; }
int Item::getStartPrice(){ return startPrice; }
string Item::getOwnerID(){ return ownerID; }
string Item::getName(){ return name; }
int Item::getBidPersonNum(){ return bidPersonNum; }

void Item::setBidPersonNum(int i_bidPersonNum){ bidPersonNum = i_bidPersonNum; }
void Item::setName(string i_name){ name = i_name; }
void Item::setItemID(int i_itemID){ itemID = i_itemID; }
void Item::setStartTime(Day i_startTime){ startTime = i_startTime; }
void Item::setEndTime(Day i_endTime){ endTime = i_endTime; }
void Item::setTotalNum(int i_totalNum){ totalNum = i_totalNum; }
void Item::setStartPrice(int i_startPrice){ startPrice = i_startPrice; }
void Item::setOwnerID(string i_ownerID){ ownerID = i_ownerID; }
