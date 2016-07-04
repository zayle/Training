#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 4;
vector<int> primes;

bool isPrime(int a) {
	int i, sr = sqrt(a);
	for (i = 0; primes[i] <= sr; i++) {
		if ((a % primes[i]) == 0) {
			return false;
		}
	}
	return true;
}

int CountFactors(int a) {
	int i;
	int count = 0;
	int sr = sqrt(a);
	for (i = 0; primes[i] <= sr; i++) {
		if ((a % primes[i]) == 0) {
			count++;
			while ((a % primes[i]) == 0) {
				a /= primes[i];
			}
			sr = sqrt(a);
		}
	}
	if (a > 1) {
		count++;
	}
	return count;
}

void Solve() {
	int i, j, count;
	primes.push_back(2);
	for (i = 3; true; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
		if (CountFactors(i) == mx) {
			count++;
			if (count == mx) {
				cout << (i - mx + 1) << '\n';
				return;
			}
		} else {
			count = 0;
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