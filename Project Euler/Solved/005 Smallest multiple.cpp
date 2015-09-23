#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 21;
int sieve[mx];

void CreateSieve() {
	int i, j;
	for (i = 2; i < mx; i++) {
		if (sieve[i] == 0) {
			for (j = i; j < mx; j += i) {
				if (sieve[j] == 0) {
					sieve[j] = i;
				} else {
					sieve[j] = -1;
				}
			}
		}
	}
}

void Solve() {
	int i;
	long long sm = 1; // smallest multiple
	for (i = 2; i < mx; i++) {
		if (sieve[i] > 1) {
			sm *= sieve[i];
		}
	}
	cout << sm << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateSieve();
	Solve();
	return 0;
}