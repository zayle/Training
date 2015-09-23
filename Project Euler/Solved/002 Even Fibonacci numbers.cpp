#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int const mx = 4000000;

void Solve() {
	int a = 1, b = 2, c, total = 2;
	while (a < mx) {
		c = a + b;
		if ((c % 2) == 0) {
			total += c;
		}
		a = b;
		b = c;
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