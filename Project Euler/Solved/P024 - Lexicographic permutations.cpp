#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 10;
const int n = 1000000;
bool used[mx];

int Factorial(int a) {
	int i;
	int factorial = 1;
	for (i = 2; i <= a; i++) {
		factorial *= i;
	}
	return factorial;
}

int GetNext(int a) {
	int i;
	for (i = 0; i < mx; i++) {
		if (!used[i]) {
			if (a == 0) {
				used[i] = true;
				return i;
			} else {
				a--;
			}
		}
	}
}

void Solve() {
	int i, aux;
	int nn = n - 1;
	for (i = 1; i < mx; i++) {
		aux = nn / Factorial(mx - i);
		nn -= (aux * Factorial(mx - i));
		cout << GetNext(aux);
	}
	cout << GetNext(0) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}