#include "Day.h"
#include "Client.h"

#include <iostream>
using namespace std;


extern Day CurrentTime;
extern Client CurrentUser;

ostream& operator<< (ostream& os, Day tmpTime) {
	os << tmpTime.year << "/" << tmpTime.month << "/" << tmpTime.day << " " << tmpTime.hour << ":00";
	return os;
}

void inform(){
	cout << CurrentUser.getName() << " " << CurrentTime << endl;
}
