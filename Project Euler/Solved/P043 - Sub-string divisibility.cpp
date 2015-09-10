#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 10;
int digits[mx] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int GetThreeAsInt(int a, int b, int c) {
	int sum = 100 * digits[a];
	sum += 10 * digits[b];
	sum += digits[c];
	return sum;
}

bool Test() {
	if ((GetThreeAsInt(1, 2, 3) %  2) != 0) return false;
	if ((GetThreeAsInt(2, 3, 4) %  3) != 0) return false;
	if ((GetThreeAsInt(3, 4, 5) %  5) != 0) return false;
	if ((GetThreeAsInt(4, 5, 6) %  7) != 0) return false;
	if ((GetThreeAsInt(5, 6, 7) % 11) != 0) return false;
	if ((GetThreeAsInt(6, 7, 8) % 13) != 0) return false;
	if ((GetThreeAsInt(7, 8, 9) % 17) != 0) return false;
	return true;
}

long long GetAllAsInt() {
	int i;
	long long a = 0;
	for (i = 0; i < mx; i++) {
		a *= 10;
		a += digits[i];
	}
	return a;
}

void Solve() {
	long long sum = 0;
	do {
		if (Test()) {
			sum += GetAllAsInt();
		}
	} while (next_permutation(digits, (digits + mx)));
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