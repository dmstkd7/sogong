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
	Client() { session = 1; privateNumber = -1; id = "!!!"; }
	Client(int c_session, string c_name) { session = c_session; name = c_name; id = "!!!"; }
	~Client() {}
	//Client() : name(""), praivateNumber(""), address(""), email(""), id(""), password("") { }
	void setSession(int c_session);
	void setName( string c_name);
	void setPrivateNumber( int c_privateNumber);
	void setAddress( string c_address);
	void setEmail( string c_email);
	void setId( string c_id);
	void setPassword( string c_password);
	
	int getSession();
	string getName();
	int getPrivateNumber();
	string getAddress();
	string getEmail();
	string getId();
	string getPassword();

	//void Print();Client의 정보를 Print하는 함수입니다.
};
/**************************CLient Collection Class****************/
class ClientCollection {
private:
	Client totalClient[10];
	
public:

	ClientCollection() {}
	~ClientCollection() {}


	void setTotalClient(int inputNum, Client newClient);

	void signUp_deleteClient();
	void signUp();
	bool deleteClient(Client wantDeleteClient);

	void Login_Logout();
	bool Login();
	bool Logout();

//	void PrintAll(Client currentUser);  // Client의 정보를 확인할 수 있는 함수입니다.

};
