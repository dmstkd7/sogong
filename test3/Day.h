#pragma once
#include <cstdio>

typedef struct Day{
	int year;
	int month;
	int day;
	int hour;

	/*
	
	void passTime(int time){
		int t_hour = (hour + time) % 24;
		int countPassMonth = (day + (hour + time) / 24) / 31;
		int tmp_day = (day + (hour + time) / 24) % 32;
		if (tmp_day == 0)
			tmp_day++;
		// '달'을 계산하고 년수가 지난만큼 계산해준다
		int countPassYear = (month + countPassMonth) / 12;
		int tmp_month = (month + countPassMonth) % 13;
		if (tmp_month == 0)
			tmp_month++;
		// '년'을 계산하고 더해준다
		int tmp_year = year + countPassYear;

		//임시로 계산된것을 입력하는 곳
		hour = t_hour;
		day = tmp_day;
		month = tmp_month;
		year = tmp_year;
		
	}
		*/

}Time;


