#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;
string names[mx + 1];

void CreateNames() {
	names[0] = "";
	names[1] = "one";
	names[2] = "two";
	names[3] = "three";
	names[4] = "four";
	names[5] = "five";
	names[6] = "six";
	names[7] = "seven";
	names[8] = "eight";
	names[9] = "nine";
	names[10] = "ten";
	names[11] = "eleven";
	names[12] = "twelve";
	names[13] = "thirteen";
	names[14] = "fourteen";
	names[15] = "fifteen";
	names[16] = "sixteen";
	names[17] = "seventeen";
	names[18] = "eighteen";
	names[19] = "nineteen";
	names[20] = "twenty";
	names[30] = "thirty";
	names[40] = "forty";
	names[50] = "fifty";
	names[60] = "sixty";
	names[70] = "seventy";
	names[80] = "eighty";
	names[90] = "ninety";
	names[100] = "hundred";
	names[1000] = "thousand";
}

int GetLetterCount(int a) {
	int count = 0;
	if (a > 999) {
		count += (names[a / 1000].size() + names[1000].size());
	}
	a = a % 1000;
	if (a > 99) {
		count += (names[a / 100].size() + names[100].size());
		if ((a % 100) > 0) {
			count += 3;
		}
	}
	a = a % 100;
	if ((1 <= a) && (a <= 19)) {
		count += names[a].size();
	} else {
		count += names[a - (a % 10)].size();
		count += names[a % 10].size();
	}
	return count;
}

void Solve() {
	int i, sum = 0;
	for (i = 1; i <= mx; i++){
		sum += GetLetterCount(i);
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateNames();
	Solve();
	return 0;
}
