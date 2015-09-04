#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
vector<int >primes; 

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
	int i;
	primes.push_back(2);
	for (i = 3; i < mx; i += 2) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
}

bool Test1(int a) {
	while (a > 0) {
		if ((a % 10) == 0) return false;
		if ((a % 10) == 2) return false;
		if ((a % 10) == 4) return false;
		if ((a % 10) == 5) return false;
		if ((a % 10) == 6) return false;
		if ((a % 10) == 8) return false;
		a /= 10;
 	}
	return true;
}

bool Test2(int a) {
	int aux = a;
	do {
		if (!isPrime(aux)) return false;
		aux += ((aux % 10) * pow(10, int(log10(aux) + 1)));
		aux /= 10;
	} while (aux != a);
	return true;
}

void Solve() {
	int i, count = 4;
	for (i = 11; i < mx; i++) {
		if (Test1(i)) {
			if (Test2(i)) {
				count++;
			}
		}
	}
	cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreatePrimes();
	Solve();
	return 0;
}