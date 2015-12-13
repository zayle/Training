#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;
vector<int> power;

void CreatePower() {
	int i, j;
	bool residue = false;
	power.push_back(1);
	for (i = 0; i < mx; i++) {
		for (j = 0; j < power.size(); j++) {
			power[j] *= 2;
			if (residue) {
				power[j]++;
				residue = false;
			}
			if (power[j] > 9) {
				power[j] = power[j] % 10;
				residue = true;
			}
		}
		if (residue) {
			power.push_back(1);
			residue = false;
		}
	}
}

void Solve() {
	int i, sum = 0;
	for (i = 0; i < power.size(); i++) {
		sum += power[i];
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreatePower();
	Solve();
	return 0;
}