#include "Client.h"

//client Å¬·¡½º ±¸Çö
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
	id = id;
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


////////// ¾ê³×´Â ¹¹ ÇÏ´Â ¾êµéÀÌÀÌÁö
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
////////// ¾ê³×´Â ¹¹ ÇÏ´Â ¾êµéÀÌÀÌÁö
BidItemCollection Client::getBidderItem() {
	return *bidderItem;
}
SellItemCollection Client::getSellerItem() {
	return sellerItem;
}
FinishItemCollection Client::getFinishItem() {
	return finishItem;
	}*/