#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
	int total = 0;
	for (int i = 3; i < 1000; i++) {
		if (((i % 3) == 0) || ((i % 5) == 0)) {
			total += i;
		}
	}
	cout << total << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}