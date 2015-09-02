#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;

int CollatzCount(long long a) {
	int chainCount = 1;
	while (a > 1) {
		if ((a % 2) == 0) {
			a /= 2;
		} else {
			a = (3 * a) + 1;
		}
		chainCount++;
	}
	return chainCount;
}

void Solve() {
	int i, count, chain = 0, number;
	for (i = 2; i < mx; i++) {
		count = CollatzCount(i);
		if (chain < count) {
			chain = count;
			number = i;
		}
	}
	cout << number << '\n';
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}