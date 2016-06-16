#include "lib.h"
#include <string.h>


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

};
