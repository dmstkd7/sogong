#pragma once
#include "FinishItemCollection.h"


extern SellItemCollection SellItemCollect;


FinishItem FinishItemCollection::getFinishItem(int i){
	return finishItem[i];
}

void FinishItemCollection::setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem){

	
	//finishItem[0].getprint();

	//finishItem[1].setTotalSoldNumber(0);
	//totalNum과 totalSoldNumber를 어떻게 넘길것인가 꼭 해결하시오//////////////////////
	finishItem[sellectFinishItem].setTotalSoldNumber(0);

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


	try{
		cout << "번호" << "        " << "경매 마감 시간" << "            " << "물품명" << endl;
		FinishItem Item;
		for (int i = 0; i < 100; i++){
			Item = getFinishItem(i);
			if (Item.getName() != ""){
				tmp.push_back(make_pair(Item.getItemID(), Item));
				cout << number++ << "        " << Item.getEndTime().year << "년 " << Item.getEndTime().month << "월 "
					<< Item.getEndTime().day << "일 " << Item.getEndTime().hour << "시간        " << Item.getName() << endl;

			}
		}
		cout << "0. 메인 메뉴로 돌아가기" << endl;



		//상세보기를 할건지 안할건지 결정하는 곳입니다
		cout << "입력선택 : ";
		cin >> command;
		if (command == 0) return;
		if (command > number) throw 1;


		if (command != 0){
			//어떤 번호를 말하는건지 잘 모르겠다 일단 아이템 아이디로 넘겨보겠다
			cout << "번호" << "       " << "경매마감시간" << "            " << "물품명" << "     " << "총판매수량" << "   " << "시작가격" << "    " << "입찰자수" << endl;
			cout << tmp[command].first << "        "
				<< tmp[command].second.getEndTime().year << "년 " << tmp[command].second.getEndTime().month << "월 "
				<< tmp[command].second.getEndTime().day << "일 " << tmp[command].second.getEndTime().hour << "시간       "
				<< tmp[command].second.getName() << "        " << tmp[command].second.getTotalSoldNumber() << "        "
				<< tmp[command].second.getStartPrice() << "        " << tmp[command].second.getBidderNumber() << endl;

		}
		cout << "0. 메인메뉴로 돌아가기" << endl;
		cin >> command;
		if (command != 0) throw 2;


	}
	catch (int type){
		if (type == 1){
			cout << "없는 상세보기를 입력하셨습니다 나가겠습니다\n" << endl;
			return;
		}

		else if (type == 2){
			cout << "입력이 0 말고는 더이상 할게 없습니다 나가겠습니다\n" << endl;
		}

	}
}



//판매중인 아이템에서 경매 마감시간이 지나 아이템을 판매완료/유찰 된 아이템으로 이동 시키는 함수이다
void FinishItemCollection::addFinishItem(){
	//FinishItem은 remainTime을 계산하여 remainTime <0 
	//것이 있따면 FinishItem()에 추가를 시킨다 
	
	SellItem Item;
	for (int i = 0; i < 100; i++){
		Item = SellItemCollect.getSellItem(i);
		//만약 경과시간이 0이라고 한다면 비어있는 값이므로 다음값을 확인 하도록한다.
		if (Item.getEndTime().year == 0)
			continue;

		//경과시간, 현재시간을 비교하는 코드입니다.
		if (Item.getRemainTime().year >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month > 0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().day >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().day == 0 && Item.getRemainTime().hour>0)
			continue;
		//만약 현재시간이 경과시간보다 늦은 시간이라면 Finish 아이템으로 옮겨야 하는데
		//밑은 이 목적을 달성해주는 코드입니다.
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
