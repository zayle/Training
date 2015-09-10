#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int Gauss(int a) {
	return ((a * (a + 1)) / 2);
}

void Solve() {
	int i;
	int s, sr;
	while(cin >> s) {
		if (s > 0) {
			sr = sqrt(2 * s);
			if (Gauss(sr) <= s) sr++;
			cout << (Gauss(sr) - s) << ' ' << sr << '\n';
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
