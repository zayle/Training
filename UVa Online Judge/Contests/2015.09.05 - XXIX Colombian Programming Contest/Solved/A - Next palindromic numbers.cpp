#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

vector<int> digits;

void ConvertInVector(string number) {
	int i;
	digits.clear();
	for (i = (number.size() - 1); i > -1; i--) {
		digits.push_back(int(number[i]) - 48);
	}
}

void ShowPalindrome() {
	int i;
	int mid = digits.size() / 2;
	for (i = (digits.size() - 1); i > mid; i--) {
		cout << digits[i];
	}
	if ((digits.size() % 2) == 0) {
		cout << digits[mid];
	} 
	for (i = mid; i < digits.size(); i++) {
		cout << digits[i];
	}
	cout << '\n';
}

int FirstPalindrome() {
	int i, j;
	int test1 = false, test2 = true;
	for (i = 0, j = (digits.size() - 1); i < j; i++, j--) {
		if (digits[i] < digits[j]) {
			test1 = true;
			test2 = true;
		} else if (digits[j] < digits[i]) {
			test2 = false;
		}
	}
	if (test1 && test2) {
		ShowPalindrome();
		return 1;
	} else {
		return 0;
	}
}
void AddOne() {
	int i;
	int residue = 1;
	int mid = digits.size() / 2;
	for (i = mid; i < digits.size(); i++) {
		digits[i] += residue;
		residue = digits[i] / 10;
		digits[i] = digits[i] % 10;
	}
	if (residue) {
		digits.push_back(residue);
	}
}

void ShowDigits() {
	int i;
	for (i = 0; i < digits.size(); i++) {
		cout << digits[i];
	}
	cout << '\n';
}

void Solve() {
	int n, i;
	string d;
	while (cin >> n >> d) {
		ConvertInVector(d);
		i = FirstPalindrome();
		for (i = i; i < n; i++) {
			AddOne();
			ShowPalindrome();
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}