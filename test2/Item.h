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
	Day	startTime;
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
	//~Item(){cout << "¼Ò¸êÀÚ" << endl;}
	~Item(){}
};