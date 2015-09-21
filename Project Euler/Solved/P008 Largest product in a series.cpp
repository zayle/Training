#include <fstream>
#include <iostream>
using namespace std;
fstream fs("P008 Largest product in a series.in.txt", fstream::in);

const int mx = 1000;
const int n = 13;
int digits[mx];

void LoadDigits() {
	int i;
	char aux;
	for (i = 0; i < mx; i++) {
		fs >> aux;
		digits[i] = (int)(aux - 48);
	}
}

void Solve() {
	int i, j;
	long long p, gp = 0;
	for (i = n; i <= mx; i++) {
		p = 1;
		for (j = 0; j < n; j++) {
			p *= digits[i + j];
		}
		if (gp < p) {
			gp = p;
		}
	}
	cout << gp << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadDigits();
	Solve();
	return 0;
}
