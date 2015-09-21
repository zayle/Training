#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fs("P013 Large sum.in.txt", fstream::in);

const int n = 100;
const int mx = 50;
vector<int> sum(mx);

void Solve() {
	int i, j, residue = 0;
	string number;
	for (i = 0; i < n; i++) {
		fs >> number;
		for (j = 0; j < mx; j++) {
			sum[j] += (int(number[(mx - 1) - j]) - 48);
		}
	}
	for (i = 0; i < mx; i++) {
		sum[i] += residue;
		residue = sum[i] / 10;
		sum[i] = sum[i] % 10;
	}
	while (residue > 0) {
		sum.push_back(residue % 10);
		residue /= 10;
	}
}

void ShowSum() {
	int i;
	for (i = (sum.size() - 1); i > -1; i--) {
		cout << sum[i];
	}
	cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	ShowSum();
	return 0;
}
