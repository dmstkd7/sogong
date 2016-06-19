// Class : Item.h
 // Description: 아이템을 구현한 코드이다
 // Created: 2016/6/15 12:34 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 2016/6/16 14:34 pmby Eunsang-Jang
 //      What : 입찰자수를 나타내는 bidPersonNum을 추가하였다
 //   2. When & Who : 2016/6/16 14:53 pmby Eunsang-Jang
 //      What : startPrice값이 원래 string이었는데 int형으로 바꾸었다

#pragma once
#include "Day.h"
#include <string>
using namespace std;


class Item{

protected:
	int itemID;
	int totalNum;
	int startPrice;
	int bidPersonNum;
	string name;
	Day startTime;
	Day endTime;
	string ownerID;

public:

	static int markItemID;
	string getOwnerID();
	string getName();
	Day getStartTime();
	Day getEndTime();
	int getTotalNum();
	int getStartPrice();
	int getItemID();
	int getBidPersonNum();

	void setBidPersonNum(int i_bidPersonNum);
	void setItemID(int i_itemID);
	void setName(string i_name);
	void setStartTime(Day i_startTime);
	void setEndTime(Day i_endTime);
	void setTotalNum(int i_totalNum);
	void setStartPrice(int i_startPrice);
	void setOwnerID(string i_OwnerID);


	Item(){}
	~Item(){}
};
