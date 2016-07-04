#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1001;

void Solve() {
	int i, aux;
	int sum = 1;
	for (i  = 3; i <= mx; i += 2) {
		aux = pow(i, 2);
		// sum += aux;
		// sum += ((aux - i) + 1);
		// sum += ((aux - (2 * i)) + 2);
		// sum += ((aux - (3 * i)) + 3);
		sum += ((4 * aux) - (6 * (i - 1)));
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