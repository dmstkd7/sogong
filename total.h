#include "lib.h"
#include <string>
#include <vector>
using namespace std;




/**********************		T			Y			P			E	********************************/

//시간 명령어
typedef struct Time{
	int year;
	int month;
	int day;
	int hour;
}Day;





/**********************		I		T		E		M	********************************/


class Item{
protected:

	string i_name;
	Day	i_startTime;
	Day i_endTime;
	int i_totalNum;
	int i_startPrice;
	string i_ownerId;
	string i_itemId;


public:


	//나머지 getset도 다 만들것
	string getItemId();
	void setItemId();


	Item(){};
	~Item(){
		cout << "소멸자" << endl;
	}

};


class SellItem : public Item {
private:
	Day i_remainTime;

public:

	string getItemId();
	Day getStartTime();
	Day getEndTime();
	Day getRemainTime();
	int getTotalNum();
	int getStartPrice();
	string getOwnerId();
	void setRemainTime(Day remaintime);
	void setItemId(string ItemId);
	void setStartTime(Day startTime);
	void setEndTime(Day endTime);
	void setTotalNum(int totalNum);
	void setStartPrice(int startPrice);
	void setOwnerId(string OwnerId);



	//기본생성자
	SellItem(){
		//cout << "생성자가 생성되었습니다 11";
	}

	//초기화 생성자 현황, 이름, 시작시간, 끝나는 시간, 남은 시간, 총 판매 수량, 시작 가격, 오너Id, 아이템 ID
	SellItem(string name, Day startTime, Day endTime, Day remainTime, int totalNum, int startPrice, string ownerId, string itemId){
		i_name = name;
		i_startTime = startTime;
		i_endTime = endTime;
		i_totalNum = totalNum;
		i_startPrice = startPrice;
		i_ownerId = ownerId;
		i_itemId = itemId;
	}
	~SellItem(){
		//cout <<// "소멸자 11" << endl;
	}

};

class FinishItem : public Item  {
protected:
	int totalSoldNumber;
	int bidderNumber;

public:
	FinishItem();
	~FinishItem(){
		cout << "소멸자" << endl;
	}

};


class BidItem : public Item{
protected:
	Day remainTime;
	int bidPrice;

public:
	BidItem();
	~BidItem(){
		cout << "소멸자" << endl;
	}
};




/**********************	c	o	l	l	e	c	t	i	o	n	********************************/

//구매 아이템에 대한 컬렉션
class BidItemCollection{
private:

public:

};

//판매 아이템에 대한 컬렉션
class SellItemCollection{
private:

	SellItem sellItem[100];

public:

	//getset 함수
	SellItem getSellItem(int i);
	void setSellItem(int i, SellItem newItem);
	void addSellItem(SellItem *additionSell);
	void deleteSellItem(SellItem *removeSell);



	void getSellItemList();
	
	
	//주소를 받아야한다 반드시 수정해야됌
//	SellItem getSellList(string ownerId);
	//SellItem findSellList(string firstValue);

	SellItemCollection(){}
	~SellItemCollection(){
		cout << "소멸자가 생성되었습니다." << endl;
	}

};


class FinishItemCollection{
private:
public:
};





/**********************		C		L		I		E		T		********************************/


//client 구현
class Client{
private:

	//0은 admin, 1 guest, 2 user
	int c_session;
	string c_name;
	string c_privateNumber;
	string c_address;
	string c_email;
	string c_id;
	string c_password;
	BidItemCollection bidderItem;
	SellItemCollection sellerItem;
	FinishItemCollection finishItem;
	//비더 , 셀러

public:

	string getName();
	void setName(string name);
	string getPrivateNumber();
	void setPrivateNumber(string privateName);
	string getAddress();
	void setAddress(string address);
	string getEmail();
	void setEmail(string email);
	string getId();
	void setId(string id);
	string getPassword();
	void setPassword(string password);
	BidItemCollection getBidderItem();
	SellItemCollection getSellerItem();
	FinishItemCollection getFinishItem();



	Client(int session, string name){ c_session = session; c_name = name; }

};




/**********************		전		방		선		언	********************************/

void managementRegisterItem(Client currentUserm, SellItemCollection totalSellItemCollection);
void registerSellItem(Client currentUser, SellItemCollection totalSellItemCollection);




