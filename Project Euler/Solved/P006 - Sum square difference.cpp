#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

int const n = 100;

void Solve() {
	int i, sum = 0;
	int gauss = (n * (n + 1)) / 2;
	for (int i = 1; i <= n; i++) {
		sum += pow(i, 2);
	}
	cout << (long long)(pow(gauss, 2) - sum) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}