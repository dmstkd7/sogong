#include <iostream>
#include <string>

using namespace std;

class Client {
private:
	int session;
	string name;
	int privateNumber;
	string address;
	string email;
	string id;
	string password;

public:
	Client() {}
	Client(int c_session, string c_name) { session = c_session; name = c_name; } 
	~Client() {}
	//Client() : name(""), praivateNumber(""), address(""), email(""), id(""), password("") { }
	void setName(string c_name);
	void setPrivateNumber(int c_privateNumber);
	void setAddress(string c_address);
	void setEmail(string c_email);
	void setId(string c_id);
	void setPassword(string c_password);
	void setSession(int c_session);

	string getName();
	int setPrivateNumber();
	string setAddress();
	string setEmail();
	string getId();
	string getPassword();
	int getSession();

	void Print();
};
 /**************************CLient Collection Class****************/
class ClientCollection {
private:
	Client totalClient[10];
	bool n[10];

public:
	
	ClientCollection() {
		for (int i = 0; i < 10; i++)
			n[i] = false;
	};
	~ClientCollection() { }

	void signUp_deleteClient(Client currentUser, ClientCollection ClientCollect);
	void signUp(Client currentUser);
	bool deleteClient(Client currentUser);

	void Login_Logout(Client currentUser, ClientCollection ClientCollect);
	bool Login(Client currentUser);
	bool Logout(int);

	//void printClient();
	void PrintAll(Client currentUser);  // 정보 입력 확인 용

};
