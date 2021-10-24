//mattdriggers.h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime> //for time
#include <string>
#include <windows.h> //adds sleep 

using namespace std;



//not using namespace std becuase it can cause confusion within the program
//use instead of endl to increase clock speed
std::time_t now = std::time(0);
tm* local_time = localtime(&now);
int hour = local_time->tm_hour;
int minute = local_time->tm_min;
int second = local_time->tm_sec;
int input;

string input2;



string Clock12() {//12 hour clock 
	if (hour > 12) {
		int hour1;
		hour1 = hour - 12;
		return to_string(hour1) + ":" + to_string(minute) + ":" + to_string(second) + " PM";
	}
	else {
		return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second) + " AM";
	}
}

string Clock24() {//24 hour clock
	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}
void addHour() {//this function adds an hour to the clock
	hour = hour + 1;
	if (hour == 24) {
		hour = 0;
	}
}
void addMin() {//this function adds1 minute to the clock
	minute = minute + 1;
	if (minute == 60) {
		minute = 0;
		addHour();
	}
}
void addSec() {//this function adds 1 second to the clock
	second = second + 1;
	if (second == 60) {
		second = 0;
		addMin();
	}
}

void main() {//int main used to return integer
	int input = 0;
	while (input != 4) {// while loop to allow us to add time to the clock until we quit
		cout << "**************************" << "    " << "**************************" << endl;
		cout << "*     12-Hour Clock      *" << "    " << "*     24-Hour Clock      *" << endl;
		cout << "*      " << Clock12() << "        *" << "    " << "*        " << Clock24() << "        *" << endl;
		cout << "**************************" << "    " << "**************************" << endl;
		//main menu
		cout << "**************************" << endl;
		cout << "*  1-Add One Hour        *" << endl;
		cout << "*  2-Add One Minute      *" << endl;
		cout << "*  3-Add One Second      *" << endl;
		cout << "*  4-Exit Program        *" << endl;
		cout << "**************************" << endl;
		cin >> input;
		addSec();
		Sleep(1000);
		//if else for decisions 
		if (input == 1) {
			addHour();
		}
		else if (input == 2) {
			addMin();
		}
		if (input == 3) {
			addSec();
		}

	}
}