#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100001;
int sieve[mx];

void CreateSieve() {
	int i, j;
	for (i = 2; i < mx; i++) {
		if (sieve[i] == 0) {
			for (j = i; j < mx; j += i) {
				if (sieve[j] == 0) {
					sieve[j] = i;
				}
			}
		}
	}
}

int GetPrimesCount(int a) {
	int count = 0;
	while (a > 1) {
		count++;
		a /= sieve[a];
	}
	return count;
}

void Solve(int a, int b) {
	int i, total = 0;
	for (i = a; i <= b; i++) {
		int pc = GetPrimesCount(i);
		if (sieve[pc] == pc) {
			total++;
		}
	}
	cout << total << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int a, b;
	cin >> a >> b;
	CreateSieve();
	Solve(a, b);
	return 0;
}