#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
bool composites[mx+1];

void Createcomposites() {
	int i, j;
	composites[0] = true;
	composites[1] = true;
	for (i = 2; i <= mx; i++) {
		if (!composites[i]) {
			for (j = i; j <= mx; j += i) {
				composites[j] = true;
			}
			composites[i] = false;
		}
	}
}

int GetPrimesCount(int a, int b) {
	int n, aux, count = 0;
	for (n = 0; true; n++) {
		aux = pow(n, 2) + (a * n) + b;
		if ((aux < 0) || (composites[aux])) {
			break;
		} else {
			count++;
		}
	}
	return count;
}

void Solve() {	
	int lmt = 999, a, b, aux, primesCount = 0, A, B;
	for (a = -lmt; a <= lmt; a++) {
		for (b = -lmt; b <= lmt; b++) {
			aux = GetPrimesCount(a, b);
			if (primesCount < aux) {
				primesCount = aux;
				A = a;
				B = b;
			}
		}
	}
	cout << (A * B) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Createcomposites();
	Solve();
	return 0;
}