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


int Item::markItemID = 0;
Client CurrentUser(1, "guest");

//�� �ݷ����� �����Ͽ���
FinishItemCollection FinishItemCollect;
SellItemCollection SellItemCollect;
BidItemCollection BidItemCollect;
ClientCollection ClientCollect;

//����ð��� ��Ÿ���� ��������
Day CurrentTime;

int main(void)
{
	

	//���� �ð� �ʱ�ȭ�� �Ѵ�
	CurrentTime.year = 2016;
	CurrentTime.month = 6;
	CurrentTime.day = 10;
	CurrentTime.hour = 12;


	//�޴� ����ġ
	int command;
	while (1){
		cout << CurrentUser.getName() << " " << CurrentTime << endl;
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
		cin.clear();
		cin.ignore(256, '\n');




		//command�� ���ڷ� ���� �� ������ �ִ�

		if (command >= 0 && command < 9){
			switch (command){
			case 1:
				ClientCollect.Login_Logout();
				break;
			case 2:
				changeSession();
				break;
			case 3:
				managementRegisterItem();
				break;
			case 4:
				managementBIdItem(CurrentUser, BidItemCollect, SellItemCollect);
				break;
			case 5:break;
				cout << "������ 3���̶� 5���� �������� �ʾҽ��ϴ�" << endl;
				break;
			case 6:
				setCurrentTime();
				break;
			case 7:
				ClientCollect.signUp_deleteClient();
				break;
			case 0:
				cout << "���α׷��� �����ŵ�ϴ�" << endl;
				return 0;
			default:
				cout << "�˸��� �ʴ� ��ȣ�Դϴ�";
				break;

			}
		}
		else{
			cout << "�˸��� �ʴ� ��ȣ�Դϴ�" << endl;

		}
	}

	
	
	return 0;
}