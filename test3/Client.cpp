#include "Client.h"

//client 클래스 구현


// Function : get 함수
 // Description: 정보를 가져오는 함수이다.
 // Parameters : 없음
 // Return Value :  해당 정보
 // Created: 2015/6/15 13:00 pm
 // Author: 전주라

// Function : set 함수
 // Description: 정보를 바꾸는 함수이다.
 // Parameters : 바꾸고 싶은 정보
 // Return Value : 없음
 // Created: 2015/6/15 13:00 pm
 // Author: 전주라
string Client::getName(){
	return name;
}
void Client::setName(string c_name){
	name = c_name;
}
string Client::getPrivateNumber(){
	return privateNumber;
}
void Client::setPrivateNumber(string c_privateName){
	privateNumber = c_privateName;
}
int Client::getEnrollNumber(){
	return enrollNumber;
	
}
void Client::setEnrollNumber(int c_enrollNumber){
	enrollNumber = c_enrollNumber;
}
string Client::getAddress(){
	return address;
}
void Client::setAddress(string c_Address){
	address = c_Address;
}
string Client::getEmail(){
	return email;
}
void Client::setEmail(string c_email){
	email = c_email;
}
string Client::getId(){
	return id;
}
void Client::setId(string c_id){
	id = c_id;
}
string Client::getPassword(){
	return password;
}
void Client::setPassword(string c_password){
	password = c_password;
}

void Client::setSession(int wantChangeNum){
	session = wantChangeNum;
}

int Client::getSession(){
	return session;
}


////////// 얘네는 뭐 하는 얘들이이지
void* Client::getBidderItem() {
	return bidderItem;
}
void* Client::getSellerItem() {
	return sellerItem;
}
void* Client::getFinishItem() {
	return finishItem;
}


/*
////////// 얘네는 뭐 하는 얘들이이지
BidItemCollection Client::getBidderItem() {
	return *bidderItem;
}
SellItemCollection Client::getSellerItem() {
	return sellerItem;
}
FinishItemCollection Client::getFinishItem() {
	return finishItem;
	}*/
