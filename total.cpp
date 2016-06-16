#include "total.h"
using namespace std;



void managementRegisterItem(Client currentUser){

	int command;

	cout << "1. 판매 물품 정보 등록" << endl;
	cout << "2. 판매 중인 물품 정보 조회" << endl;
	cout << "3. 판매 종료/유 물품 조회" << endl;
	cout << "0. 메인 메뉴로 돌아가기" << endl;
	cout << "입력 선택 : ";

	while (1){
		cin >> command;

		switch (command){
		case 1:
			cout << "1. 판매 물품 정보 등록으로 들어갑니다" << endl;
			registerSellItem(currentUser);
			break;
		case 2:
			cout << "2. 아직 구현 안햇쪙" << endl;
			break;
		case 3:
			cout << "3. 아직 구현 안햇쪙" << endl;
			break;
		case 0:
			cout << "메인 메뉴로 돌아가겠습니다" << endl;
			return;
			break;
		default:
			cout << "명령어 입력이 올바르지 않습니다. 다시 입력해주세요" << endl;
			continue;

		}
	}
	return;


}

void registerSellItem(Client currentUser){

	string name, ownerID, itemId;
	name = currentUser.getName();
	ownerID = currentUser.getId();
	itemId = "12";
	int totalNum, startPrice;
	Time startTime, endTime, remainTime;

	cout << "물품명을 입력하세요 : ";
	scanf("%s", &name);
	cout << "\n" << "총판매수량을 입력하세요 : ";
	scanf("%d", &totalNum);
	cout << "\n" << "시작 가격을 입력하세요 : ";
	scanf("%d", &startPrice);
	cout << "\n" << "경매 시작시간을 입력하세요 년 : ";
	scanf("%d", &startTime.year);
	cout << "\n" << "경매 시작시간을 입력하세요 월 : ";
	scanf("%d", &startTime.month);
	cout << "\n" << "경매 시작시간을 입력하세요 일 : ";
	scanf("%d", &startTime.day);
	cout << "\n" << "경매 시작시간을 입력하세요 시간 : ";
	scanf("%d", &startTime.hour);
	cout << "\n" << "경매 종료시간을 입력하세요 년 :";
	scanf("%d", &endTime.year);
	cout << "\n" << "경매 종료시간을 입력하세요 월 : ";
	scanf("%d", &endTime.month);
	cout << "\n" << "경매 종료시간을 입력하세요 일 : ";
	scanf("%d", endTime.day);
	cout << "\n" << "경매 종료시간을 입력하세요 시간 : ";
	scanf("%d", &endTime.hour);

	remainTime.year = startTime.year - endTime.year;
	remainTime.month = startTime.month - endTime.month;
	remainTime.day = startTime.day - endTime.day;
	remainTime.hour = startTime.hour - endTime.hour;


	

	cout << "\n" << "메뉴 등록이 완료되었습니다" << endl;


	return;
}













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
	c_password = password;
}
