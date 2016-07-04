#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 10001;
vector<int> primes;

bool isPrime(int a) {
	int i;
	for (i = 0; i < primes.size(); i++) {
		if ((a % primes[i]) == 0) {
			return false;
		}
	}
	return true;
}

int Solve() {
	int aux = 2;
	while (primes.size() < mx) {
		if (isPrime(aux)) {
			primes.push_back(aux);
		}
		aux++;
	}
	cout << primes[mx - 1] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}