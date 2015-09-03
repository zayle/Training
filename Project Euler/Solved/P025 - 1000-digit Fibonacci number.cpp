#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;
vector<int> a;
vector<int> b;
vector<int> c;

void ShowC() {
	int i;
	for (i = (c.size() - 1); i > -1; i--) {
		cout << c[i];
	}
	cout << '\n';
}

void Solve() {
	int i, index = 0, residue = 1;
	a.push_back(0);
	b.push_back(0);
	c.push_back(0);
	while (c.size() < mx) {
		index++;
		for (i = 0; i < b.size(); i++) {
			c[i] = a[i] + b[i] + residue;
			residue = c[i] / 10;
			c[i] = c[i] % 10;
		}
		if (residue > 0) {
			a.push_back(0);
			b.push_back(0);
			c.push_back(residue);
			residue = 0;
		}
		a = b;
		b = c;
	}
	cout << index << ' ';
	ShowC();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}