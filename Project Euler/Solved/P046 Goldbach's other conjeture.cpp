#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
//fstream fs("in.txt", fstream::in);

vector<int> primes;

bool isPrime(int a) {
	if (a == 1) return false;
	int i, sr = sqrt(a);
	for (i = 0; primes[i] <= sr; i++) {
		if ((a % primes[i]) == 0) {
			return false;
		}
	}
	return true;
}

void Solve() {
	int i, j;
	bool aux;
	primes.push_back(2);
	for (i = 3; true; i += 2) {
		if (isPrime(i)) {
			primes.push_back(i);
		} else {
			aux = true;
			for (j = 1; (2 * pow(j, 2) < i); j++) {
				if (isPrime(i - (2 * pow(j, 2)))) {
					aux = false;
				}
			}
			if (aux) {
				cout << i << '\n';
				return;
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