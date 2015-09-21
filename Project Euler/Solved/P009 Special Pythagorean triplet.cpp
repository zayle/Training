#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;

void Solve() {
	int a, b, aux, c;
	for (a = 1; a < mx; a++) {
		for (b = (a + 1); (a + b) < mx; b++) {
			aux = pow(a, 2) + pow(b, 2);
			c = sqrt(aux);
			if (aux == pow(c, 2)) {
				if ((a + b + c) == mx) {
					cout << (a * b * c) << '\n';
					return;
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}