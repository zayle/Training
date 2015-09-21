#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 500;
vector<int> primes;

bool isPrime(int a) {
	int i, sr = sqrt(a);
	for (i = 0; i < primes.size(); i++) {
		if (primes[i] <= sr) {
			if ((a % primes[i]) == 0) {
				return false;
			}
		} else {
			break;
		}
	}
	return true;
}

int GetDivisorsCount(int a) {
	int i, aux, divisors = 1;
	for (i = 0; i < primes.size(); i++) {
		if ((a % primes[i]) == 0) {
			aux = 0;
			while ((a % primes[i]) == 0) {
				aux++;
				a /= primes[i];
			}
			divisors *= (aux + 1);
		}
	}
	if (a > 1) {
		divisors *= 2;
	}
	return divisors;
}

void Solve() {
	int i, triangular = 0;
	for (i = 2; true; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
		triangular += (i - 1);
		if (GetDivisorsCount(triangular) > mx) {
			cout << triangular << '\n';
			return;
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