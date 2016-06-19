
#include "utility.h"
#include "collection.h"

extern Day CurrentTime;
extern Client CurrentUser;



void querySellItem(){
	cout << "************** �Ǹ����� ��ǰ ���� ��ȸ �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;
	SellItemCollect.getSellItemList();
	return;
}


void queryFinishItem(){
	cout << "************** �Ǹ�/���� ���� ��ȸ �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;
	FinishItemCollect.addFinishItem();
	FinishItemCollect.getFinishItemList();
	return;
}


void changeSession(){
	cout << "************** ������ �ٲٷ� ���̱��� �ݰ����ϴ� **************" << endl;
	int command;

	cout << "1.Admin" << endl;
	cout << "2.Guest" << endl;
	//�̰� ������ �ǹ��ϴ°��� �ƴ��� �𸣰ڴ�
	cout << "3.User" << endl;
	cout << "0.���� �޴��� ���ư���" << endl;
	cin >> command;

	switch (command){
	case 1:
		CurrentUser.setSession(0);
		//cout << "���� Ŀ��Ʈ ���� " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 2:
		CurrentUser.setSession(1);
		//cout << "���� Ŀ��Ʈ ���� " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 3:
		CurrentUser.setSession(2);
		//cout << "���� Ŀ��Ʈ ���� " << CurrentUser.getSession() << CurrentUser.getName() << endl;
		break;
	case 0:
		return;
	default:
		cout << "�߸��� ���� �Է��ϼ̽��ϴ� ���� �ٲٱ⸦ �����մϴ�" << endl;
		break;
	}

}


//��ǰ ��� ������ �ϴ� â�Դϴ�
void managementRegisterItem(){

	int command;
	while (1){
		cout << "1. �Ǹ� ��ǰ ���� ���" << endl;
		cout << "2. �Ǹ� ���� ��ǰ ���� ��ȸ" << endl;
		cout << "3. �Ǹ� ����/���� ��ǰ ��ȸ" << endl;
		cout << "0. ���� �޴��� ���ư���" << endl;
		cout << "�Է� ���� : ";

		cin >> command;
		if (command == 0) return;

		switch (command){
		case 1:
			cout << "1. �Ǹ� ��ǰ ���� ������� ���ϴ�" << endl;
			SellItemCollect.addSellItem();
			break;
		case 2:
			cout << "2. �Ǹ� ���� ��ǰ ���� ��ȸ�� ���ϴ�." << endl;
			querySellItem();
			break;
		case 3:
			cout << "3. �Ǹ� ����/���� ��ǰ ��ȸ" << endl;
			queryFinishItem();
			break;
		case 0:
			cout << "0. ���� �޴��� ���ư��ڽ��ϴ�" << endl;
			return;
			break;
		default:
			cout << "��ɾ� �Է��� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���" << endl;
			continue;

		}
	}
	return;

}

//��� �ð��� �Է��ϴ� ���Դϴ�
void setCurrentTime(){
	//����ð��� ��� �Է½�Ű��

	cout << "************** ����ð��� �Է��ϴ� ���Դϴ�. **************" << endl;
	cout << "����ð���" << CurrentTime.year << "�� " << CurrentTime.month << "�� " << CurrentTime.day << "�� " << CurrentTime.hour << "�ð� " << endl;
	//int tmp;
	/*
	cout << "��� �ð��� �Է��Ͻÿ�";
	cin >> tmp;
	CurrentTime.passTime(tmp);
	*/
	
	int tmp;
	while (1){
		try{
			cout << "�� ������ �����Ͻðڽ��ϱ� : ";
			cin >> tmp;
			CurrentTime.year = tmp;
			if (CurrentTime.year < 0) throw 1;
			cout << "�� ������ �����Ͻðڽ��ϱ� : ";
			cin >> tmp;
			CurrentTime.month = tmp;
			if (CurrentTime.month < 0 || CurrentTime.month > 12) throw 1;
			cout << "�� ������ �����Ͻðڽ��ϱ� : ";
			cin >> tmp;
			CurrentTime.day = tmp;
			if (CurrentTime.day < 0 || CurrentTime.day > 31) throw 1;
			cout << "�� �ð����� �����Ͻðڽ��ϱ� : ";
			cin >> tmp;
			CurrentTime.hour = tmp;
			if (CurrentTime.hour < 0 || CurrentTime.hour > 24) throw 1;
			break;
		}
		catch (int type){
			if (type == 1){
				cout << "�ùٸ� ����ð��� �Է����ֽñ� �ٶ��ϴ�. ";
			}
		}
	}
	

	cout << "�ٲ� ����ð��� " << CurrentTime.year << "�� " << CurrentTime.month << "�� " << CurrentTime.day << "�� " << CurrentTime.hour << "�ð� " << endl;


}



void managementBIdItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect) {
	int command = 0;
	while (1) {
		cout << "- 4. ��� ��ǰ ��ȸ, ���� ����" << endl;
		cout << "1. ��� ���� ��ǰ ��ȸ" << endl;
		cout << "2. ���� ���� ���� ��ȸ" << endl;
		cout << "0. ���θ޴��� ���ư���" << endl;

		cout << "* �Է¼��� : ";
		cin >> command;
		switch (command) {
		case 0: return;
		case 1: queryBidItem(currentUser, BidItemCollect, SellItemCollect); return;
		case 2: queryMyBidItem(currentUser, BidItemCollect); return;
		default:
			cout << "�˸��� ���� ��ȣ�Դϴ�." << endl;
		}
	}
}

void queryBidItem(Client currentUser, BidItemCollection BidItemCollect, SellItemCollection SellItemCollect) {
	string search;
	cout << "- 4.1. ��� ���� ��ǰ ��ȸ" << endl;
	cout << "# ��� ��ǰ�� Ű���带 �Է��ϼ��� : ";
	cin >> search;
	SellItemCollect.findSellList(currentUser, search, BidItemCollect);

	return;
}

void queryMyBidItem(Client currentUser, BidItemCollection BidItemCollect) {
	string search;
	cout << "- 4.2. ���� ���� ��ǰ ��ȸ" << endl;
	BidItemCollect.getBidList(currentUser);

	return;
}