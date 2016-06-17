#include "total.h"

extern SellItemCollection SellItemCollect;



void registerSellItem(Client currentUser, SellItemCollection totalSellItemCollection){

	cout << "\n\n\n" << "************** 물품 등록을 하러 오셨군요 반갑습니다 **************" << endl;


	string name, ownerId, itemId;
	name = currentUser.getName();
	ownerId = currentUser.getId();
	itemId = "12";
	int totalNum, startPrice;
	Time startTime, endTime, remainTime;


	//freopen("input.txt", "r", stdin);

	cout << "물품명을 입력하세요 : ";
	cin >> name;
	cout << "총판매수량을 입력하세요 : ";
	cin >> totalNum;
	cout << "시작 가격을 입력하세요 : ";
	cin >> startPrice;
	cout << "경매 시작시간을 입력하세요 년 : ";
	cin >> startTime.year;
	cout << "경매 시작시간을 입력하세요 월 : ";
	cin >> startTime.month;
	cout << "경매 시작시간을 입력하세요 일 : ";
	cin >> startTime.day;
	cout << "경매 시작시간을 입력하세요 시간 : ";
	cin >> startTime.hour;
	cout << "경매 종료시간을 입력하세요 년 :";
	cin >> endTime.year;
	cout << "경매 종료시간을 입력하세요 월 : ";
	cin >> endTime.month;
	cout << "경매 종료시간을 입력하세요 일 : ";
	cin >> endTime.day;
	cout << "경매 종료시간을 입력하세요 시간 : ";
	cin >> endTime.hour;

	remainTime.year = endTime.year - startTime.year;
	remainTime.month = endTime.month - startTime.month;
	remainTime.day = endTime.day - startTime.day;
	remainTime.hour = endTime.hour - startTime.hour;

	cout << name << endl;

	SellItem *newItem = new SellItem(name, startTime, endTime, remainTime, totalNum, startPrice, ownerId, itemId);
	totalSellItemCollection.addSellItem(newItem);

	//SellItemCollection collect = currentUser.getSellerItem();
	//collect.addSellItem(newItem);

	
	cout << "\n" << "메뉴 등록이 완료되었습니다" << endl;

	return;
}




void querySellItem(Client currentUser, SellItemCollection totalSellItemCollection){

	cout << "\n\n\n" << "************** 판매중인 물품 정보 조회 하러 오셨군요 반갑습니다 **************" << endl;

	totalSellItemCollection.getSellItemList();

	return;
}


void managementRegisterItem(Client currentUser, SellItemCollection totalSellItemCollection){

	int command;


	
	while (1){


		cout << "1. 판매 물품 정보 등록" << endl;
		cout << "2. 판매 중인 물품 정보 조회" << endl;
		cout << "3. 판매 종료/유 물품 조회" << endl;
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "입력 선택 : ";


		cin >> command;

		switch (command){
		case 1:
			cout << "1. 판매 물품 정보 등록으로 들어갑니다" << endl;
			registerSellItem(currentUser, totalSellItemCollection);
			break;
		case 2:
			cout << "2. 판매 중인 물품 정보 조회로 들어갑니다." << endl;
			querySellItem(currentUser, totalSellItemCollection);
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





/********************************		클		래		스		구		현		********************************/




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


BidItemCollection Client::getBidderItem(){
	return bidderItem;
}
SellItemCollection Client::getSellerItem(){
	return sellerItem;
}
FinishItemCollection Client::getFinishItem(){
	return finishItem;
}




SellItem SellItemCollection::getSellItem(int i){
	return sellItem[i];
}


void SellItemCollection::setSellItem(int i, SellItem newItem){
	sellItem[i] = newItem;
}

void SellItemCollection::addSellItem(SellItem *additionSell){


	printf("여기까지 오는데 성공했구나\n");
	for (int i = 0; i < 100; i++){
		SellItem item = getSellItem(i);
		if (item.getItemId() == ""){
			setSellItem(i, *additionSell);
			cout << "완료하였습니다``11";
			break;
		}
			
	}
	


}

void SellItemCollection::getSellItemList(){
	
	printf("여기까지 또 왔구나 성공했구나\n");
	for (int i = 0; i < 100; i++){
		SellItem item = getSellItem(i);
		cout << item.getItemId() << endl;

	}

}

//bool deleteSellItem(SellItem removeSell){}



//SellItem getSellList(string ownerId){}




//SellItem findSellList(string firstValue){}





/////////// class Item 구현 /////////////////
string Item::getItemId(){
	return i_itemId;
}




/////////// class SellItem 구현 ///////////////
string SellItem::getItemId(){
	return i_itemId;
}


Day SellItem::getStartTime(){ return i_startTime; }
Day SellItem::getEndTime(){ return i_endTime; }
Day SellItem::getRemainTime(){ return i_remainTime; }
int SellItem::getTotalNum(){ return i_totalNum; }
int SellItem::getStartPrice(){ return i_startPrice; }
string SellItem::getOwnerId(){ return i_ownerId; }
void SellItem::setItemId(string itemId){ i_itemId = itemId; }
void SellItem::setStartTime(Day startTime){ i_startTime = startTime; }
void SellItem::setEndTime(Day endTime){ i_endTime = endTime; }
void SellItem::setTotalNum(int totalNum){ i_totalNum = totalNum; }
void SellItem::setStartPrice(int startPrice){ i_startPrice = startPrice; }
void SellItem::setOwnerId(string ownerId){ i_ownerId = ownerId; }













