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
		// '��'�� ����ϰ� ����� ������ŭ ������ش�
		int countPassYear = (month + countPassMonth) / 12;
		int tmp_month = (month + countPassMonth) % 13;
		if (tmp_month == 0)
			tmp_month++;
		// '��'�� ����ϰ� �����ش�
		int tmp_year = year + countPassYear;

		//�ӽ÷� ���Ȱ��� �Է��ϴ� ��
		hour = t_hour;
		day = tmp_day;
		month = tmp_month;
		year = tmp_year;
		
	}
		*/

}Time;


