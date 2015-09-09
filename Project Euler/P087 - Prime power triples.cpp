#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 50000000;
vector<int> primes;
vector<int> numbers;

void CreatePrimes() {
	int i, j, lmt = sqrt(sqrt(mx));
	vector<bool> composites((lmt+1), false);
	for (i = 2; i <= lmt; i++) {
		if (!composites[i]) {
			primes.push_back(i);
			for (j = i; j <= lmt; j += i) {
				composites[j] = true;
			}
			composites[i] = false;
		}
	}
}

void Solve() {
	int i, j, k, aux;
	for (i = 0; i < primes.size(); i++) {
		for (j = 0; j < primes.size(); j++) {
			for (k = 0; k < primes.size(); k++) {
				aux = pow(primes[i], 2) + pow(primes[j], 3) + pow(primes[k], 4);
				if (aux < mx) {
					numbers.push_back(aux);
				}
			}
		}
	}
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
