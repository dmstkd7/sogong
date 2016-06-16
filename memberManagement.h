#include <iostream>
#include <string>
using namespace std;

class Client {
private:
	string c_name;
	int c_privateNum;
	string c_address;
	string c_email;
	string c_ID;
	string c_PW;

public:
	Client() : c_name(""), c_privateNum(-1), c_address(""), c_email(""), c_ID(""), c_PW("") { }
	void SetName(string);
	void SetADD(string);
	void SetEMAIL(string);
	void SetID(string);
	void SetPW(string);
	void Print();
	string GetID();
	string GetPW();
	int GetPrivateNum();
	void SetPRIVATENUM (int);

};

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
	void SignUp();
	void PrintAll();

	int Login();
	//void Login(); //로그인
//	void Logout();  //로그아웃
	//int SetState(int);
};

