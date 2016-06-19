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



// Class : Client
 // Description: Client의 정보를 갖는class이다. 
 //  각 client는 세션, 이름, 주민번호, 주소, 이메일, ID, PW
// 가입번호를 갖는다. 
 // get 함수는 client의 정보를 반환해주고,
 // set 함수는 client의 정보를 셋팅한다.
 // client가 생성될 때는 session, enrollNumber, id가 설정된다.
 // Created: 2015/6/15 13:00 pm
 // Author: 전주라
 // mail: j161021@hanmail.net

class Client{
private:

	//0Àº admin, 1 guest, 2 user
	int session;
	string name;
	string privateNumber;
	string address;
	string email;
	string id;
	string password;
	int enrollNumber;//가입번호
	BidItemCollection *bidderItem;
	SellItemCollection *sellerItem;
	FinishItemCollection *finishItem;
	//ºñ´õ , ¼¿·¯

public:

	int getSession();
	void setSession(int wantChangeSession);
	string getName();
	void setName(string c_name);
	int getPrivateNumber();
	void setPrivateNumber(int c_privateNumber);
	string getAddress();
	void setAddress(string c_address);
	string getEmail();
	void setEmail(string c_email);
	string getId();
	void setId(string c_id);
	string getPassword();
	void setPassword(string c_password);
	int getEnrollNumber();
	void setEnrollNumber(int c_enrollNumber);
	void* getBidderItem();
	void* getSellerItem();
	void* getFinishItem();

	Client() { session = 1; privateNumber = -1; id = "!!!"; }
	//Client(){}
	Client(int c_session, string c_name){ session = c_session; name = c_name; session = 1; privateNumber = -1; id = "!!!";}
	~Client(){}

};
