#pragma once
#include "Item.h"
#include "Day.h"


class SellItem : public Item {
private:
	Day remainTime;

public:

	Day getRemainTime();
	void setRemainTime(Day remaintime);

	//�⺻������
	//SellItem(){ cout << "SellItem ������" << endl; }
	SellItem(){}

	//�ʱ�ȭ ������ ��Ȳ, �̸�, ���۽ð�, ������ �ð�, ���� �ð�, �� �Ǹ� ����, ���� ����, ����Id, ������ ID
	//�����ð��� ���� �ð��� ���ؾ� ��
	SellItem(string i_name, Day i_startTime, Day i_endTime, Day i_remainTime, int i_totalNum, int i_startPrice, string i_ownerID, int i_itemID){
		name = i_name;
		startTime = i_startTime;
		endTime = i_endTime;
		totalNum = i_totalNum;
		startPrice = i_startPrice;
		ownerID = i_ownerID;
		itemID = i_itemID;
		bidPersonNum = 0;

	}
	//~SellItem(){ cout << "SellItem �Ҹ���" << endl; }
	~SellItem(){}
};