#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

long long n, nn;

bool Test1() {
	long long a = n;
	while (a > 0) {
		if ((a % 10) == 3) return true;
		if ((a % 10) == 4) return true;
		if ((a % 10) == 7) return true;
		a /= 10;
	}
	return false;
}

void Turn() {
	long long a = n;
	while (a > 0) {
		nn *= 10;
		if ((a % 10) == 0) nn += 0;
		if ((a % 10) == 1) nn += 1;
		if ((a % 10) == 2) nn += 2;
		if ((a % 10) == 5) nn += 5;
		if ((a % 10) == 6) nn += 9;
		if ((a % 10) == 8) nn += 8;
		if ((a % 10) == 9) nn += 6;
		a /= 10;
	}
}

bool Test2() {
	long long i;
	long long srN  = sqrt(n);
	long long srNN = sqrt(nn);
	for (i = 3; (i <= srN) || (i <= srNN); i += 2) {
		if (i <= srN) {
			if ((n % i) == 0) return true;
		}
		if (i <= srNN) {
			if ((nn % i) == 0) return true;
		}
	}
	return false;
}

void Solve() {
	string answer = "no";
	if (n > 2) {
		if (!Test1()) {
			Turn();
			if (!Test2()) {
				answer = "yes";
			}
		}
	}
	if (n == 2) answer = "yes";
	cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> n;
	Solve();
	return 0;
}