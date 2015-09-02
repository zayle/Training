#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int exponent = 5;
const int mx = pow(9, exponent) * 6;

int GetSumOfDigits(int a) {
	int sum = 0;
	while (a > 0) {
		sum += pow((a % 10), exponent);
		a /= 10;
	}
	return sum;
}

void Solve() { 
	int i;
	int sum = 0;
	for (i = 10; i <= mx; i++) {
		if (i == GetSumOfDigits(i)) {
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
	Solve();
	return 0;
}