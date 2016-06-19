#pragma once
#include "FinishItemCollection.h"
#include "BidItemCollection.h"

extern SellItemCollection SellItemCollect;
extern BidItemCollection BidItemCollect;

FinishItem FinishItemCollection::getFinishItem(int i){
	return finishItem[i];
}

void FinishItemCollection::setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem){

	
	//finishItem[0].getprint();

	//finishItem[1].setTotalSoldNumber(0);
	//totalNum�� totalSoldNumber�� ��� �ѱ���ΰ� �� �ذ��Ͻÿ�//////////////////////
	finishItem[sellectFinishItem].setTotalSoldNumber(0);

	finishItem[sellectFinishItem].setItemID(newItem.getItemID());
	finishItem[sellectFinishItem].setStartPrice(newItem.getStartPrice());
	finishItem[sellectFinishItem].setName(newItem.getName());
	finishItem[sellectFinishItem].setStartTime(newItem.getStartTime());
	finishItem[sellectFinishItem].setEndTime(newItem.getEndTime());
	finishItem[sellectFinishItem].setOwnerID(newItem.getOwnerID());

	SellItem FreshItem;
	BidItem b_FreshItem;
	SellItemCollect.setSellItem(sellectSellItem, FreshItem);
	BidItemCollect.setBidItem(sellectSellItem, b_FreshItem);

}


void FinishItemCollection::getFinishItemList(){

	int number = 1;
	//��µǴ� ��ȣ�� ItemId�� �����ϱ� ���� ����
	vector< pair<int, FinishItem>> tmp;
	int command = 0;


	//�̰��� �ϴ� ������ ��µǴ� ��ȣ�� ItemID�� ��ġ ��Ű�� ���� �����Ⱚ�� �־�δ� ���̴�
	FinishItem trash;
	tmp.push_back(make_pair(0, trash));


	try{
		cout << "��ȣ" << "        " << "��� ���� �ð�" << "            " << "��ǰ��" << endl;
		FinishItem Item;
		for (int i = 0; i < 100; i++){
			Item = getFinishItem(i);
			if (Item.getName() != ""){
				tmp.push_back(make_pair(Item.getItemID(), Item));
				cout << number++ << "        " << Item.getEndTime().year << "�� " << Item.getEndTime().month << "�� "
					<< Item.getEndTime().day << "�� " << Item.getEndTime().hour << "�ð�        " << Item.getName() << endl;

			}
		}
		cout << "0. ���� �޴��� ���ư���" << endl;



		//�󼼺��⸦ �Ұ��� ���Ұ��� �����ϴ� ���Դϴ�
		cout << "�Է¼��� : ";
		cin >> command;
		cin.clear();
		cin.ignore(256, '\n');
		if (command == 0) return;
		if (command >= number) throw 1;


		if (command != 0){
			//� ��ȣ�� ���ϴ°��� �� �𸣰ڴ� �ϴ� ������ ���̵�� �Ѱܺ��ڴ�
			cout << "��ȣ" << "       " << "��Ÿ����ð�" << "            " << "��ǰ��" << "     " << "���Ǹż���" << "   " << "���۰���" << "    " << "�����ڼ�" << endl;
			cout << tmp[command].first << "        "
				<< tmp[command].second.getEndTime().year << "�� " << tmp[command].second.getEndTime().month << "�� "
				<< tmp[command].second.getEndTime().day << "�� " << tmp[command].second.getEndTime().hour << "�ð�       "
				<< tmp[command].second.getName() << "        " << tmp[command].second.getTotalSoldNumber() << "        "
				<< tmp[command].second.getStartPrice() << "        " << tmp[command].second.getBidderNumber() << endl;

		}
		cout << "0. ���θ޴��� ���ư���" << endl;
		cin >> command;
		cin.clear();
		cin.ignore(256, '\n');
		if (command != 0) throw 2;


	}
	catch (int type){
		if (type == 1){
			cout << "���� �󼼺��⸦ �Է��ϼ̽��ϴ� �����ڽ��ϴ�\n" << endl;
			return;
		}

		else if (type == 2){
			cout << "�Է��� 0 ����� ���̻� �Ұ� �����ϴ� �����ڽ��ϴ�\n" << endl;
		}

	}
}



//�Ǹ����� �����ۿ��� ��� �����ð��� ���� �������� �ǸſϷ�/���� �� ���������� �̵� ��Ű�� �Լ��̴�
void FinishItemCollection::addFinishItem(){
	//FinishItem�� remainTime�� ����Ͽ� remainTime <0 
	//���� �ֵ��� FinishItem()�� �߰��� ��Ų�� 
	
	SellItem Item;
	for (int i = 0; i < 100; i++){
		Item = SellItemCollect.getSellItem(i);
		//���� ����ð��� 0�̶�� �Ѵٸ� ����ִ� ���̹Ƿ� �������� Ȯ�� �ϵ����Ѵ�.
		if (Item.getEndTime().year == 0)
			continue;

		//����ð�, ����ð��� ���ϴ� �ڵ��Դϴ�.
		if (Item.getRemainTime().year >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month > 0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().day >0)
			continue;
		if (Item.getRemainTime().year == 0 && Item.getRemainTime().month == 0 && Item.getRemainTime().day == 0 && Item.getRemainTime().hour>0)
			continue;
		//���� ����ð��� ����ð����� ���� �ð��̶�� Finish ���������� �Űܾ� �ϴµ�
		//���� �� ������ �޼����ִ� �ڵ��Դϴ�.
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
