#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fs("in.txt", fstream::in);

vector<int> primes;
long long n;

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

void CreatePrimes() {
	int i, cr = cbrt(n);
	for (i = 2; i <= cr; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
}

void Solve() {
	long long i, j, cr, aux, divisors = 1;
	cr = cbrt(n);
	for (i = 0; i < primes.size(); i++) {
		if ((n % primes[i]) == 0) {
			aux = 1;
			while ((n % primes[i]) == 0) {
				aux++;
				n /= primes[i];
			}
			divisors *= aux;
		}
	}
	if (n > 1) {
		
		if (pow(sqrt(n), 2) == n) {
			divisors *= 3;
		} else {
			divisors *= 4;
		}
	}
	cout << divisors << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	fs >> n;
	CreatePrimes();
	Solve();
	return 0;
}