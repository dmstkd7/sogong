#include "total.h"
using namespace std;



//client 클래스 구현

string Client::getName(){
	return c_name;
}
void Client::setName(string name){
	c_name = name;
}
string Client::getPrivateNumber(){
	return c_privateNumber;
}
void Client::setPrivateNumber(string privateName){
	c_privateNumber = privateName;
}
string Client::getAddress(){
	return c_address;
}
void Client::setAddress(string Address){
	c_address = Address;
}
string Client::getEmail(){
	return c_email;
}
void Client::setEmail(string email){
	c_email = email;
}
string Client::getId(){
	return c_id;
}
void Client::setId(string id){
	c_id = id;
}
string Client::getPassword(){
	return c_password;
}
void Client::setPassword(string password){
	c_password = password}
