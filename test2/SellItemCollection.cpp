#include "SellItemCollection.h"
#include "BidItemCollection.h"
#include "Client.h"
#include <vector>


extern Client CurrentUser;
extern Day CurrentTime;

ostream& operator<< (ostream& os, Day tmpTime);


//SellectionCollection���� private�� totalSellItem�� �������� get �Լ��Դϴ�.
SellItem SellItemCollection::getSellItem(int i){
	return totalSellItem[i];
}

//totalSellItem���� wantChange��ȣ�� newItem�� �߰� ��Ű�� �Լ��Դϴ�.
void SellItemCollection::setSellItem(int wantChangeNum, SellItem newItem){
	totalSellItem[wantChangeNum] = newItem;
}



void SellItemCollection::addSellItem(){

	cout << "************** ��ǰ ����� �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;


	string name, ownerID;
	name = CurrentUser.getName();
	ownerID = CurrentUser.getId();
	int totalNum, startPrice;
	Day startTime, endTime, remainTime;
	while (1){
		try{
			cout << "��ǰ���� �Է��ϼ��� : ";
			cin >> name;
			if (name.length() < 2) throw 1;
			cout << "���Ǹż����� �Է��ϼ��� : ";
			cin >> totalNum;
			if (totalNum< 0) throw 2;
			cout << "���� ������ �Է��ϼ��� : ";
			cin >> startPrice;
			if (startPrice< 0) throw 3;
			cout << "��� ���۽ð��� �Է��ϼ��� �� : ";
			cin >> startTime.year;
			if (startTime.year < CurrentTime.year) throw 4;
			cout << "��� ���۽ð��� �Է��ϼ��� �� : ";
			cin >> startTime.month;
			if ((startTime.year == CurrentTime.year) && startTime.month < CurrentTime.month) throw 4;
			if (startTime.month > 12) throw 6;
			cout << "��� ���۽ð��� �Է��ϼ��� �� : ";
			cin >> startTime.day;
			if ((startTime.year == CurrentTime.year) && (startTime.month == CurrentTime.month) && startTime.day < CurrentTime.day) throw 4;
			if (startTime.day > 31) throw 6;
			cout << "��� ���۽ð��� �Է��ϼ��� �ð� : ";
			cin >> startTime.hour;
			if ((startTime.year == CurrentTime.year) && (startTime.month == CurrentTime.month) && (startTime.day == CurrentTime.day) && startTime.hour < CurrentTime.hour) throw 4;
			if (startTime.hour > 24) throw 6;

			cout << "��� ����ð��� �Է��ϼ��� �� :";
			cin >> endTime.year;
			if (endTime.year < CurrentTime.year) throw 4;
			if (endTime.year < startTime.year) throw 5;
			cout << "��� ����ð��� �Է��ϼ��� �� : ";
			cin >> endTime.month;
			if ((endTime.year == CurrentTime.year) && endTime.month < CurrentTime.month) throw 4;
			if ((endTime.year == startTime.year) && endTime.month < startTime.month) throw 5;
			if (endTime.month > 12) throw 6;
			cout << "��� ����ð��� �Է��ϼ��� �� : ";
			cin >> endTime.day;
			if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && endTime.day < CurrentTime.day) throw 4;
			if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && endTime.day < startTime.day) throw 5;
			if (endTime.day > 31) throw 6;
			cout << "��� ����ð��� �Է��ϼ��� �ð� : ";
			cin >> endTime.hour;
			if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && (endTime.day == CurrentTime.day) && endTime.hour < CurrentTime.hour) throw 4;
			if ((endTime.year == CurrentTime.year) && (endTime.month == CurrentTime.month) && (endTime.day == CurrentTime.day) && endTime.hour < startTime.hour) throw 5;
			if (endTime.hour > 24) throw 6;

			remainTime.year = endTime.year - CurrentTime.year;
			remainTime.month = endTime.month - CurrentTime.month;
			remainTime.day = endTime.day - CurrentTime.day;
			remainTime.hour = endTime.hour - CurrentTime.hour;
			break;
		}
		catch (int type){
			switch (type){
			case 1:
				cout << "��ǰ���� ��� 2���� �̻� �����ּ���" << endl;
				break;
			case 2:
				cout << "�� �Ǹż����� 0�� �̻����� �����ּ���" << endl;
				break;
			case 3:
				cout << "���۰����� 0�� �̻����� �����ּ���" << endl;
				break;
			case 4:
				cout << "����ð����� �� ���� ������ ���� �����ϴ�." << endl;
				break;
			case 5:
				cout << "�����ð��� ���۽ð����� ���� ���� �����ϴ�" << endl;
				break;
			case 6:
				cout << "������ ���� �ʴ� �� �Դϴ�." << endl;
			}
			cout << "�ٽ� �Է��ϼ��� " << endl;
			continue;
		}
	}

	SellItem newItem(name, startTime, endTime, remainTime, totalNum, startPrice, ownerID, Item::markItemID++);

	SellItem item;
	for (int i = 0; i < 100; i++){
		item = getSellItem(i);
		if (item.getName() == ""){
			setSellItem(i, newItem);
			break;
		}

	}
	cout << "\n" << "�޴� ����� �Ϸ�Ǿ����ϴ�" << endl;

	return;
}

void SellItemCollection::getSellItemList(){

	int number = 1;
	//��µǴ� ��ȣ�� ItemId�� �����ϱ� ���� ����
	vector< pair<int, SellItem>> tmp;
	int command = 0;


	//�̰��� �ϴ� ������ ��µǴ� ��ȣ�� ItemID�� ��ġ ��Ű�� ���� �����Ⱚ�� �־�δ� ���̴�
	SellItem trash;
	tmp.push_back(make_pair(0, trash));

	try{
		cout << "��ȣ" << "   " << "�� ǰ ��" << "   " << "�� �Ǹż���" << "     " << "���� ����" << endl;
		SellItem Item;
		for (int i = 0; i < 100; i++){
			Item = getSellItem(i);
			if (Item.getName() != ""){
				tmp.push_back(make_pair(Item.getItemID(), Item));
				cout << number++ << "        " << Item.getName() << "        " << Item.getTotalNum() << "             " << Item.getStartPrice() << endl;
			}
		}
		cout << "0. ���� �޴��� ���ư���" << endl;



		//�󼼺��⸦ �Ұ��� ���Ұ��� �����ϴ� ���Դϴ�
		cout << "�Է¼��� : ";
		cin >> command;
		if (command == 0) return;
		if (command > number) throw 1;


		if (command != 0){
			//� ��ȣ�� ���ϴ°��� �� �𸣰ڴ� �ϴ� ������ ���̵�� �Ѱܺ��ڴ�
			cout << "��ȣ" << "  " << "�� ǰ ��" << "   " << "�� �Ǹż���" << "   " << "���� ����" << "   " << "������ ��" << "        " << "��Ÿ����ð�" << endl;
			cout << tmp[command].first << "      " << tmp[command].second.getName() << "         " << tmp[command].second.getTotalNum()
				<< "           " << tmp[command].second.getStartPrice() << "        " << tmp[command].second.getBidPersonNum() << "        "
				<< tmp[command].second.getEndTime().year << "�� " << tmp[command].second.getEndTime().month << "�� "
				<< tmp[command].second.getEndTime().day << "�� " << tmp[command].second.getEndTime().hour << "�ð� "
				<< endl;
		}
		cout << "0. ���� �޴��� ���ư���" << endl;
		cout << "�Է¼��� : ";
		cin >> command;
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
	return;
}


void SellItemCollection::findSellList(Client currentUser, string search, BidItemCollection BidItemCollect) {
	int tCollection[100];
	int chk = 0;
	int input;
	int num = 1;

	for (int i = 0; i < 100; i++) {
		if (search == totalSellItem[i].getName()) {
			tCollection[chk] = totalSellItem[i].getItemID();
			cout << "��ȣ	" << "�̸�	" << "�����ð�	" << "����	" << endl;
			cout << num << "	" << totalSellItem[i].getName() << "	";
			cout << totalSellItem[i].getRemainTime() << "	" << totalSellItem[i].getStartPrice() << endl;
			num++;
			chk++;
		}
	}

	cout << "0. ���� �޴��� ���ư���" << endl;
	cout << "* �Է¼��� : ";
	cin >> input;
	if (input == 0) {
		return;
	}
	else {
		input--;
		getSellItem(currentUser, input, tCollection, BidItemCollect);
	}
}


void SellItemCollection::getSellItem(Client currentUser, int num, int* sellList, BidItemCollection BidItemCollect) {
	int chk = sellList[num];
	int i = 0;
	int input;

	cout << "-4.1.1." << num << " ���õ� ��ǰ�� �� ��ȸ" << endl;

	while (chk != totalSellItem[i].getItemID()) { i++; }
	cout << totalSellItem[i].getName() << " ";
	cout << totalSellItem[i].getStartTime() << " ";
	cout << totalSellItem[i].getEndTime() << " ";
	cout << totalSellItem[i].getTotalNum() << " ";
	cout << totalSellItem[i].getStartPrice() << " ";
	cout << totalSellItem[i].getOwnerID() << " ";
	cout << totalSellItem[i].getItemID() << " ";
	cout << totalSellItem[i].getRemainTime() << endl;

	cout << "1. ��������" << endl;
	cout << "0. ���� �޴��� ���ư���" << endl;
	cout << "* �Է¼��� : ";
	cin >> input;
	if (input == 1) {
		BidItemCollect.addBidItem(currentUser, totalSellItem[i]);
	}
}
