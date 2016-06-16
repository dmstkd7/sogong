#include "lib.h"
#include <string.h>
using namespace std;


/**********************		T			Y			P			E	********************************/

//시간 명령어
typedef struct Time{
	int year;
	int month;
	int day;
	int hour;
}Day;



/**********************	c	o	l	l	e	c	t	i	o	n	********************************/

//구매 아이템에 대한 컬렉션
class BidItemCollection{
private:

public:

};

//판매 아이템에 대한 컬렉션
class SellItemCollection{
private:
public:
};


class FinishItemCollection{
private:
public:
};


/**********************		I		T		E		M	********************************/


class Item{
protected:

	string name;
	Day	startTime;
	Day endTime;
	int totalNum;
	int startPrice;
	string ownerId;
	string itemId;

public:
	Item();
	~Item(){
		cout << "소멸자" << endl;
	}

};


class SellItem : public Item {
private :
	Day remainTime;

public:
	SellItem();
	~SellItem(){
		cout << "소멸자" << endl;
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

	Client(int session, string name){ c_session = session; c_name = name; }

};




/**********************		전		방		선		언	********************************/

void managementRegisterItem(Client currentUser);
void registerSellItem(Client currentUser);
