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

//각 콜렉션을 선언하였다
FinishItemCollection FinishItemCollect;
SellItemCollection SellItemCollect;
BidItemCollection BidItemCollect;
ClientCollection ClientCollect;

//현재시간을 나타내는 전역변수
Day CurrentTime;

int main(void)
{
	

	//현재 시간 초기화를 한다
	CurrentTime.year = 2016;
	CurrentTime.month = 6;
	CurrentTime.day = 10;
	CurrentTime.hour = 12;


	//메뉴 스위치
	int command;
	while (1){
		cout << CurrentUser.getName() << " " << CurrentTime << endl;
		cout << "1. Login/Logout" << endl;
		cout << "2. Session 선택/변경" << endl;
		cout << "3. 물품 등록 관리" << endl;
		cout << "4. 경매 물품 조회, 입찰 관리" << endl;
		cout << "5. 구매 완료/낙찰 실패 물품 정보 확인" << endl;
		cout << "6. 경과시간 입력" << endl;
		cout << "7. 회원가입/탈퇴" << endl;
		cout << "0. 종료" << endl;

		cout << "* 입력 선택 : ";
		cin >> command;
		cin.clear();
		cin.ignore(256, '\n');




		//command가 문자로 왔을 때 문제가 있다

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
				cout << "조원이 3명이라 5번은 구현하지 않았습니다" << endl;
				break;
			case 6:
				setCurrentTime();
				break;
			case 7:
				ClientCollect.signUp_deleteClient();
				break;
			case 0:
				cout << "프로그램을 종료시킵니다" << endl;
				return 0;
			default:
				cout << "알맞지 않는 번호입니다";
				break;

			}
		}
		else{
			cout << "알맞지 않는 번호입니다" << endl;

		}
	}

	
	
	return 0;
}