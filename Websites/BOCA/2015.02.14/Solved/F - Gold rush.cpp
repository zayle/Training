#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

long long n, a, b;

void Solve() {
	int days = -1;
	long long weight = pow(2, n);
	while (a > 0) {
		if (weight <= a) {
			a -= weight;
		}
		weight /= 2;
		days++;
	}
	cout << days << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int t;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n >> a >> b;
		Solve();
	}
	return 0;
}