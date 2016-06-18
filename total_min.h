#include "lib.h"
#include <string>
#include <vector>
using namespace std;

class Client;


/**********************		T			Y			P			E	********************************/

//시간 명령어
typedef struct Time {
	int year;
	int month;
	int day;
	int hour;
}Day;

Day copyDay(Day oldTime, Day tmpTime);

/**********************		oI		T		E		M	********************************/

class Item {

protected:
	int itemID;
	int totalNum;
	int startPrice;
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

	void setItemID(int i_itemID);
	void setName(int i_name);
	void setStartTime(Day i_startTime);
	void setEndTime(Day i_endTime);
	void setTotalNum(int i_totalNum);
	void setStartPrice(int i_startPrice);
	void setOwnerID(string i_OwnerID);


	Item() {}
	//~Item(){cout << "소멸자" << endl;}
	~Item() {}
};


class SellItem : public Item {
private:
	Day remainTime;

public:

	Day getRemainTime();
	//void setRemainTime(Day remaintime);

	//기본생성자
	//SellItem(){ cout << "SellItem 생성자" << endl; }
	SellItem() {}
	
	//초기화 생성자 현황, 이름, 시작시간, 끝나는 시간, 남은 시간, 총 판매 수량, 시작 가격, 오너Id, 아이템 ID
	SellItem(string i_name, Day i_startTime, Day i_endTime, Day i_remainTime, int i_totalNum, int i_startPrice, string i_ownerID, int i_itemID) {
		name = i_name;
		startTime = i_startTime;
		endTime = i_endTime;
		totalNum = i_totalNum;
		startPrice = i_startPrice;
		ownerID = i_ownerID;
		itemID = i_itemID;

	}
	//~SellItem(){ cout << "SellItem 소멸자" << endl; }
	~SellItem() {}
};


class FinishItem : public Item {
private:
	int totalSoldNumber;
	int bidderNumber;

public:

	int getTotalSoldNumber();
	int getBidderNumber();


	//얘는 set이 있어야 하나 절대로 수정되어선 안되는건데?

	FinishItem() {};
	~FinishItem() {}

};


class BidItem : public Item {
protected:
	Day remainTime;
	int bidPrice;

public:
	BidItem() {}
	BidItem(string bname, Day bstartTime, Day bendTime, int btotalNum, int bstartPrice, string bownerID, int bitemID, int bbidPrice) {
		name = bname;
		startTime = bstartTime;
		endTime = bendTime;
		totalNum = btotalNum;
		startPrice = bstartPrice;
		ownerID = bownerID;
		itemID = bitemID;
		bidPrice = bbidPrice;
	}
	~BidItem() {
		//cout << "소멸자" << endl;
	}
	Day getRemainTime();
	int getBidPrice();
	void setRemainTime();
};




/**********************	s	e	l	l	I	t	e	m	c	o	l	l	e	c	t	i	o	n	********************************/

//구매 아이템에 대한 컬렉션
class BidItemCollection {
private:
	BidItem totalBidItem[100] ;
public:
	void setBidItem(int, BidItem);
	void getBidItem(int, int*);
	void getBidList(Client);
	void addBidItem(Client, SellItem);

	int getNumberBid(int);

	BidItemCollection() {} // BIdItemCollection 생성자를 어떻게?? BidItem 생성자가 없다는데? default 값을 줘야하나 생성자에??
	~BidItemCollection() {}
};

//판매 아이템에 대한 컬렉션
class SellItemCollection {
private:
	SellItem totalSellItem[100];
public:
	void addSellItem();
	SellItem getSellItem(int i);
	void setSellItem(int i, SellItem newItem);
	void getSellItemList();
	void findSellList(Client, string, BidItemCollection);
	void getSellItem(Client, int, int*, BidItemCollection);


	//생성자 소멸자
	SellItemCollection() {}
	~SellItemCollection() { /*cout << "소멸자가 생성되었습니다." << endl;*/ }

};


class FinishItemCollection {
private:
	FinishItem finishItem[100];

public:

	FinishItem getFinishItem(int i);
	void getFinishItemList();
	void addFinishItem();
	void setFinishItem(int i, FinishItem newItem);

	FinishItemCollection() {}
	~FinishItemCollection() {}
};



/**********************		C		L		I		E		T		********************************/

//client 구현
class Client {
private:

	//0은 admin, 1 guest, 2 user
	int session;
	string name;
	string privateNumber;
	string address;
	string email;
	string id;
	string password;
	BidItemCollection bidderItem;
	SellItemCollection sellerItem;
	FinishItemCollection finishItem;
	//비더 , 셀러

public:
	string getName();
	void setName(string c_name);
	string getPrivateNumber();
	void setPrivateNumber(string c_privateName);
	string getAddress();
	void setAddress(string c_address);
	string getEmail();
	void setEmail(string c_email);
	string getId();
	void setId(string c_id);
	string getPassword();
	void setPassword(string c_password);
	BidItemCollection getBidderItem();
	SellItemCollection getSellerItem();
	FinishItemCollection getFinishItem();



	Client(int c_session, string c_name, string c_id) { session = c_session; name = c_name; id = c_id; }
	Client() {}
	~Client() {}

};







/**************************CLient Collection Class****************/
class ClientCollection {
private:
	Client* totalClient = new Client[10];
	bool n[10];

public:
	ClientCollection() {
		for (int i = 0; i < 10; i++)
			n[i] = false;
	};
	~ClientCollection() { delete[] totalClient; }

	void signUp_deleteClient(Client currentUser, ClientCollection ClientCollect);
	void signUp(Client currentUser);
	bool deleteClient(Client currentUser);

	void Login_Logout(Client currentUser, ClientCollection ClientCollect);
	bool Login(Client currentUser);
	int Logout(int);

	//void printClient();
	//	void PrintAll(Client currentUser);  //// 정보 입력 확인 용

};





/**********************		전		방		선		언	********************************/

void managementRegisterItem();
void setCurrentTime();
void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect);
void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect);
void querySellItem();
void queryFinishItem();
