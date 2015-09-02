#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 28124;
bool abundant[mx];

int GetDivisorsSum(int a) {
	int i;
	int sum = 1, sr = sqrt(a);
	for (i = 2; i <= sr; i++) {
		if ((a % i) == 0) {
			sum += i;
			if (i < (a / i)) {
				sum += (a / i);
			}
		}
	}
	return sum;
}

void CreateAbundantNumbers() {
	int i;
	for (i = 1; i < mx; i++) {
		if (i < GetDivisorsSum(i)) {
			abundant[i] = true;
		}
	}
}

bool isSumOfAbundantNumbers(int a) {
	int i;
	for (i = 0; i <= a; i++) {
		if (abundant[i] && abundant[a - i]) {
			return true;
		}
	}
	return false;
}

void Solve() {
	int i;
	int sum = 1;
	for (i = 2; i < mx; i++) {
		if (!isSumOfAbundantNumbers(i)) {
			sum += i;
		}
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateAbundantNumbers();
	Solve();
	isSumOfAbundantNumbers(31);
	return 0;
}