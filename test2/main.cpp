#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Day.h"
#include "Item.h"
#include "BidItem.h"
#include "BidItemCollection.h"
#include "Client.h"
#include "ClientCollection.h"
#include "SellItem.h"
#include "SellItemCollection.h"
#include "FinishItem.h"
#include "FinishItemCollection.h"
#include "utility.h"

using namespace std;




//��ü �ǸŸ� �����ϴ� 
int Item::markItemID = 0;
Client CurrentUser(1, "guest");
FinishItemCollection FinishItemCollect;
SellItemCollection SellItemCollect;
BidItemCollection BidItemCollect;

//����ð��� ��Ÿ���� ��������
Day CurrentTime;

int main(void)
{
	//�ð��ʱ�ȭ ���߿� Ŭ������ ���ڰ� �����ؾ� �Ѵ�
	//���۷��̼� �ϼ̴ٴ°� ��� �ǹ��ϴ��� ���� ���庸��
	CurrentTime.year = 2016;
	CurrentTime.month = 6;
	CurrentTime.day = 1;
	CurrentTime.hour = 12;


	int command;

	//���� ���� ������ �������� ��Ÿ���ִ� Ŭ�����̴�
	while (1){
		cout << "1. Login/Logout" << endl;
		cout << "2. Session ����/����" << endl;
		cout << "3. ��ǰ ��� ����" << endl;
		cout << "4. ��� ��ǰ ��ȸ, ���� ����" << endl;
		cout << "5. ���� �Ϸ�/���� ���� ��ǰ ���� Ȯ��" << endl;
		cout << "6. ����ð� �Է�" << endl;
		cout << "7. ȸ������/Ż��" << endl;
		cout << "0. ����" << endl;

		cout << "* �Է� ���� : ";
		cin >> command;

		switch (command){
		case 1:
			break;
		case 2:break;
			changeSession();
			break;
			//�ǸŹ�ǰ��ϰ����� �Ѿ��
		case 3:
			managementRegisterItem();
			break;
		case 4:
			managementBIdItem(CurrentUser, BidItemCollect, SellItemCollect);
			break;
		case 5:break;
		case 6:
			setCurrentTime();
			break;
		case 7:

			break;
		case 0:
			cout << "���α׷��� �����ŵ�ϴ�" << endl;
			return 0;
		default:
			cout << "�˸��� �ʴ� ��ȣ�Դϴ�";
			break;


		}
	}
	
	
	return 0;
}