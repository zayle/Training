#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int dayOfWeek = 2; // Tuesday
int day = 1;
int month = 1;
int year = 1901;

void AddDay() {
	dayOfWeek = (dayOfWeek + 1) % 7;
	day++;
	if (month == 2) {
		if (((year %   4) ==   0)
	    &&  ((year % 400) != 100)
	    &&  ((year % 400) != 200)
	    &&  ((year % 400) != 300)) {
	    	if (day == 30) {
	    		day = 1;
	    		month++;
	    	}
		} else {
			if (day == 29) {
				day = 1;
				month++;
			}
		}
	} else if ((month == 4)
		   ||  (month == 6)
		   ||  (month == 9)
		   ||  (month == 11)) {
		if (day == 31) {
			day = 1;
			month++;
		}
	} else {
		if (day == 32) {
			day = 1;
			month++;
		}
		if (month == 13) {
			month = 1;
			year++;
		}
	}
}

void Solve() {
	int count = 0;
	while (!((day == 31) && (month == 12) && (year == 2000))) {
		AddDay();
		if ((dayOfWeek == 0) && (day == 1)) {
			count++;
		}
	}
	cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}