#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100;
vector<int> factorial;

void CreateFactorial() {
	int i, j, residue = 0;
	factorial.push_back(1);
	for (i = 2; i <= mx; i++) {
		for (j = 0; j < factorial.size(); j++ ) {
			factorial[j] = (i * factorial[j]) + residue;
			residue = factorial[j] / 10;
			factorial[j] = factorial[j] % 10;
		}
		while (residue > 0) {
			factorial.push_back(residue % 10);
			residue /= 10;
		}
	}
}

void Solve() {
	int i, sum = 0;
	for (i = 0; i < factorial.size(); i++) {
		sum += factorial[i];
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateFactorial();
	Solve();
	return 0;
}