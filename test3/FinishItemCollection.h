// Class : FinishItemCollection.h
 // Description: FinishItem에 대한 콜렉션을 구현한 코드입니다.
 //  ……………………………………….
 //  ………………………………………
 // Created: 2016/6/15 20:12 pm
 // Author: 장은상
 // mail: eeunsang7@naver.com
 //
 // Revsions : 
 //   1. When & Who : 2016/06/17 23:11 pm by eunsang-Jang
 //      What : 생성자만 구현하였다가 나머지 getFinishItemList()같은 것을 직접 구현하였다


#pragma once
#include "FinishItem.h"
#include "SellItem.h"
#include "SellItemCollection.h"
#include "BidItem.h"
#include <vector>


class FinishItemCollection{
private:
	FinishItem finishItem[100];
public:
	// Function : FinishItem getFinishItem(int i)
	 // Description: 기본 get/set함수이다 콜렉션 안에 finishItem을 리턴한다
	 // Parameters :   int i - 100개 중에 얻고 싶은 finishItem의 번호이다
	 // Return Value :  FinishItem
	 // Created: 2016/6/15 20:15 pm
	 // Author: 장은상
	FinishItem getFinishItem(int i);
	
	// Function : void getFinishItemList();
	 // Description: FinishItem 중에 의미 있는 값을 모두 출력하는 것으로 판매완료/유출된 아이템의 조회를 
	 //		 하는것과 같다
	 // Parameters :   없다
	 // Return Value :  없다
	 // Created: 2016/6/15 20:16 pm
	 // Author: 장은상
	void getFinishItemList();
	// Function : void addFinishItem();
	 // Description: FinishItemCollection에 FinishItem를 추가 시키는것이다 보통 판매중인 것이 시간이 끝나면
	 //		자동적으로 이쪽으로 오게된다 그때 작동하는 함수이다
	 // Parameters :   없다
	 // Return Value :  없다
	 // Created: 2016/6/15 20:18 pm
	 // Author: 장은상
	void addFinishItem();
	
	 // void setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem);
	 // Description: 판매중인 아이템중 남은시간이 종료한 것을 판매가 종료된 아이템으로 바꿀 때 콜렉션에
	 //		 설정하는 함수이다
	 // Parameters :   int selectSellItem - 삭제해야하는 SellItemcollection에서의 번호
	 //		   int sellecFinishItem - SellFinishCollection에서 들어갈 수 있는 번호
	 //		   SellItem newItem - 판매중에서 판매종료아이템으로 바꾸려고 하는 아이템
	 // Return Value :  없다
	 // Created: 2016/6/15 20:32 pm
	 // Author: 장은상
	void setFinishItem(int sellectSellItem, int sellectFinishItem, SellItem newItem);

	FinishItemCollection(){}
	~FinishItemCollection(){}
};
