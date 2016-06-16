#include <iostream>
#include <string>
using namespace std;

class Client {
private:
	string name;
	string praivateNum;
	string address;
	string email;
	string ID;
	string PW;

public:
	Client() : name(""), praivateNum(""), address(""), email(""), ID(""), PW("") { }
	void MakeName(string str);
	//void MakePN(string str) { praivateNum = str; }
	void MakeADD(string str);
	void MakeEMAIL(string str);
	void MakeID(string str);
	void MakePW(string str);


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
	void signUp();

};
