#include "total.h"




extern SellItemCollection SellItemCollect;
extern FinishItemCollection FinishItemCollect;
extern BidItemCollection BidItemCollect;
extern Client CurrentUser;
extern Day CurrentTime;


void querySellItem(){

	cout << "************** 판매중인 물품 정보 조회 하러 오셨군요 반갑습니다 **************" << endl;

	SellItemCollect.getSellItemList();

	return;
}


void queryFinishItem(){
	

	cout << "************** 판매/종료 유찰 조회 하러 오셨군요 반갑습니다 **************" << endl;
	FinishItemCollect.addFinishItem();
	FinishItemCollect.getFinishItemList();
	return;
}


void changeSession(){

	int command;
	cout << "************** 세션을 바꾸러 오셨군요 반갑습니다 **************" << endl;

	cout << "1.Admin" << endl;
	cout << "2.Guest" << endl;
	//이게 유저를 의미하는건지 아닌지 모르겠다
	cout << "3.User" << endl;
	cout << "0.메인 메뉴로 돌아가기" << endl;
	cin >> command;

	switch (command){
	case 1:
		CurrentUser.setSession(0);
		break;
	case 2:
		CurrentUser.setSession(1);
		break;
	case 3:
		CurrentUser.setSession(2);
		break;
	default :
		//다시 실행시킬지 말지 정하자
		cout << "잘못된 값을 입력하셨습니다 프로그램을 종료합니다";
		break;
	}


	return;
}


//물품 등록 관리를 하는 창입니다
void managementRegisterItem(){

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
			SellItemCollect.addSellItem();
			break;
		case 2:
			cout << "2. 판매 중인 물품 정보 조회로 들어갑니다." << endl;
			querySellItem();
			break;
		case 3:
			cout << "3. 판매 종료/유찰 물품 조회" << endl;
			queryFinishItem();
			break;
		case 0:
			cout << "0. 메인 메뉴로 돌아가겠습니다" << endl;
			return;
			break;
		default:
			cout << "명령어 입력이 올바르지 않습니다. 다시 입력해주세요" << endl;
			continue;

		}
	}
	return;

	
}

//경과 시간을 입력하는 곳입니다
void setCurrentTime(){
	
	cout << "************** 경과시간을 입력하는 곳입니다. **************" << endl;

	int tmp;

	cout << "몇 년으로 설정하시겠습니까 : ";
	cin >> tmp;
	CurrentTime.year = tmp;
	cout << "몇 월으로 설정하시겠습니까 : ";
	cin >> tmp;
	CurrentTime.month = tmp;
	cout << "몇 일으로 설정하시겠습니까 : ";
	cin >> tmp;
	CurrentTime.day = tmp;
	cout << "몇 시간으로 설정하시겠습니까 : ";
	cin >> tmp;
	CurrentTime.hour = tmp;
	

}




/********************************		클		래		스		구		현		********************************/




//client 클래스 구현
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


////////// 얘네는 뭐 하는 얘들이이지
BidItemCollection Client::getBidderItem(){
	return bidderItem;
}
SellItemCollection Client::getSellerItem(){
	return sellerItem;
}
FinishItemCollection Client::getFinishItem(){
	return finishItem;
}



/***********************	FinishItem class 구현	*************************/

int FinishItem::getTotalSoldNumber(){ return totalSoldNumber; }
int FinishItem::getBidderNumber(){ return bidderNumber; }


void FinishItem::setTotalSoldNumber(int i_totalSoldNumber){ totalSoldNumber = i_totalSoldNumber; }
void FinishItem::setBidderNumber(int i_bidderNumer){ bidderNumber = i_bidderNumer; }


/***********************	FinishItemCollection class 구현	*************************/




FinishItem FinishItemCollection::getFinishItem(int i){
	return finishItem[i];
}

void FinishItemCollection::setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem){

	//totalNum과 totalSoldNumber를 어떻게 넘길것인가 꼭 해결하시오//////////////////////
	finishItem[sellectFinishItem].setTotalSoldNumber(1111);

	finishItem[sellectFinishItem].setItemID(newItem.getItemID());
	finishItem[sellectFinishItem].setStartPrice(newItem.getStartPrice());
	finishItem[sellectFinishItem].setName(newItem.getName());
	finishItem[sellectFinishItem].setStartTime(newItem.getStartTime());
	finishItem[sellectFinishItem].setEndTime(newItem.getEndTime());
	finishItem[sellectFinishItem].setOwnerID(newItem.getOwnerID());

	SellItem FreshItem;
	SellItemCollect.setSellItem(sellectSellItem, FreshItem);
	
	
}


void FinishItemCollection::getFinishItemList(){

	int number = 1;
	//출력되는 번호와 ItemId를 연결하기 위한 변수
	vector< pair<int, FinishItem>> tmp;
	int command = 0;


	//이것을 하는 이유는 출력되는 번호와 ItemID를 일치 시키기 위해 쓰레기값을 넣어두는 것이다
	FinishItem trash;
	tmp.push_back(make_pair(0, trash));

	cout << "번호" << "        " << "경매 마감 시간" << "            " << "물품명" << endl;
	FinishItem Item;
	for (int i = 0; i < 100; i++){
		Item = getFinishItem(i);
		if (Item.getName() != ""){
			tmp.push_back(make_pair(number, Item));
			cout << number++ << "        " << Item.getEndTime().year << "년 " << Item.getEndTime().month << "월 "
				<< Item.getEndTime().day << "일 " << Item.getEndTime().hour << "시간        " << Item.getName() << endl;
				 
		}
	}
	cout << "0. 메인 메뉴로 돌아가기" << endl;



	//상세보기를 할건지 안할건지 결정하는 곳입니다
	cout << "입력선택 : ";
	cin >> command;

	if (command != 0){
		//어떤 번호를 말하는건지 잘 모르겠다 일단 아이템 아이디로 넘겨보겠다

		cout << "번호" << "               " << "경매마감시간" << "    " << "물품명" << "      " << "총판매수량" << "      " << "시작가격" << "    " << "입찰자수" << endl;
		cout << tmp[command].first << "        "
			<< tmp[command].second.getEndTime().year << "년 " << tmp[command].second.getEndTime().month << "월 "
			<< tmp[command].second.getEndTime().day << "일 " << tmp[command].second.getEndTime().hour << "시간 "
			<< tmp[command].second.getName() << "        " << tmp[command].second.getTotalSoldNumber() << "        "
			<< tmp[command].second.getStartPrice() << "        " << tmp[command].second.getBidderNumber() << endl;

	}
	else
		return;
}


void FinishItemCollection::addFinishItem(){
	//FinishItem은 remainTime을 계산하여 remainTime <0 
	//것이 있따면 FinishItem()에 추가를 시킨다 



	SellItem Item;
	for (int i = 0; i < 100; i++){
		Item = SellItemCollect.getSellItem(i);
		if (Item.getEndTime().year == 0)
			continue;
		printf("%d %d %d %d %d %d %d %d\n", Item.getEndTime().year, Item.getEndTime().month, Item.getEndTime().day, Item.getEndTime().hour,
			CurrentTime.year, CurrentTime.month, CurrentTime.day, CurrentTime.hour);
		if (Item.getRemainTime().year >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month > 0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().day >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().hour>0)
			continue;
		//이제 추가시킨다
		FinishItem FItem;
		for (int j = 0; j < 100; j++){
			FItem = getFinishItem(j);
			if (FItem.getName() == ""){
				cout << Item.getName() << endl;
				setFinishItem(i, j, Item);
				break;
			}
		}

	}


	
}






SellItem SellItemCollection::getSellItem(int i){
	return totalSellItem[i];
}


void SellItemCollection::setSellItem(int i, SellItem newItem){
	cout << "지금 입력하려고 하는 아이템은 " << newItem.getName() << i <<  endl;
	totalSellItem[i] = newItem;
}



void SellItemCollection::addSellItem(){

	cout  << "************** 물품 등록을 하러 오셨군요 반갑습니다 **************" << endl;


	string name, ownerID;
	//itemID는 나중에 처리하겠따
	int itemID = 12;
	name = CurrentUser.getName();
	ownerID = CurrentUser.getId();
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

	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;

	cout << name << endl;

	//SellItem *newItem = new SellItem(name, startTime, endTime, remainTime, totalNum, startPrice, ownerID, Item::markItemID);

	SellItem newItem(name, startTime, endTime, remainTime, totalNum, startPrice, ownerID, Item::markItemID++);

	SellItem item;
	for (int i = 0; i < 100; i++){
		//getSellItem이 없어져야해
		item = getSellItem(i);
		if (item.getName() == ""){
			setSellItem(i, newItem);
			break;
		}
			
	}
	
	cout << "\n" << "메뉴 등록이 완료되었습니다" << endl;

	return;
}

void SellItemCollection::getSellItemList(){
	
	int number = 1;
	//출력되는 번호와 ItemId를 연결하기 위한 변수
	vector< pair<int, SellItem>> tmp;
	int command = 0;
	

	//이것을 하는 이유는 출력되는 번호와 ItemID를 일치 시키기 위해 쓰레기값을 넣어두는 것이다
	SellItem trash;
	tmp.push_back(make_pair(0, trash));

	printf("여기는 getSellItemList 입니다\n");

	cout << "번호" << "   " << "물 품 명" << "   " << "총 판매수량" << "   " << "시작 가격" << endl;
	SellItem Item;
	for (int i = 0; i < 100; i++){
		Item = getSellItem(i);
		if (Item.getName() != ""){
			tmp.push_back(make_pair(number, Item));
			cout << number++ << "        " << Item.getName() << "        " << Item.getTotalNum() << "        " << Item.getStartPrice() << endl;
		}
	}
	cout << "0. 메인 메뉴로 돌아가기" << endl;
	


	//상세보기를 할건지 안할건지 결정하는 곳입니다
	cout << "입력선택 : ";
	cin >> command;

	if (command != 0){
		//어떤 번호를 말하는건지 잘 모르겠다 일단 아이템 아이디로 넘겨보겠다
		cout << "번호" << "  " << "물 품 명" << "   " << "총 판매수량" << "   " << "시작 가격" << " " << "입찰자 수" << "     " << "경매마감시간" << endl;
		cout << tmp[command].first << "      " << tmp[command].second.getName() << "       " << tmp[command].second.getTotalNum()
			<< "                " << tmp[command].second.getStartPrice() << "              " << "입찰자 수" << "        " 
			<< tmp[command].second.getEndTime().year << "년 " << tmp[command].second.getEndTime().month << "월 "
			<< tmp[command].second.getEndTime().day << "일 " << tmp[command].second.getEndTime().hour << "시간 "
			<< endl;
	}
	else
		return;
}


/////////// class Item 구현 /////////////////
int Item::getItemID(){
	return itemID;
}
Day Item::getStartTime(){ return startTime; }
Day Item::getEndTime(){ return endTime; }
Day SellItem::getRemainTime(){ 
	//SellItem에 remainTime이 의미가 없는것 같은데?
	//의문점을 꼭 해결하시오
	//대문자 소문자 이거도 꼭맞추시오
	remainTime.year = endTime.year - CurrentTime.year;
	remainTime.month = endTime.month - CurrentTime.month;
	remainTime.day = endTime.day - CurrentTime.day;
	remainTime.hour = endTime.hour - CurrentTime.hour;
	return remainTime;
}
int Item::getTotalNum(){ return totalNum; }
int Item::getStartPrice(){ return startPrice; }
string Item::getOwnerID(){ return ownerID; }
string Item::getName(){ return name; }


void Item::setName(string i_name){ name = i_name; }
void Item::setItemID(int i_itemID){ itemID = i_itemID; }
void Item::setStartTime(Day i_startTime){ startTime = i_startTime; }
void Item::setEndTime(Day i_endTime){ endTime = i_endTime; }
void Item::setTotalNum(int i_totalNum){ totalNum = i_totalNum; }
void Item::setStartPrice(int i_startPrice){ startPrice = i_startPrice; }
void Item::setOwnerID(string i_ownerID){ ownerID = i_ownerID; }













