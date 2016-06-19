#pragma once
//#include "BidItemCollection.h"
//#include "SellItemCollection.h"
//#include "FinishItemCollection.h"
#include <string>
#include "Day.h"
using namespace std;

class BidItemCollection;
class SellItemCollection;
class FinishItemCollection;




class Client{
private:

	//0�� admin, 1 guest, 2 user
	int session;
	string name;
	string privateNumber;
	string address;
	string email;
	string id;
	string password;
	BidItemCollection *bidderItem;
	SellItemCollection *sellerItem;
	FinishItemCollection *finishItem;
	//��� , ����

public:

	int getSession();
	void setSession(int wantChangeSession);
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
	void* getBidderItem();
	void* getSellerItem();
	void* getFinishItem();


	Client(){}
	Client(int c_session, string c_name){ session = c_session; name = c_name; }
	~Client(){}

};