#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const long long prime = 600851475143;
const int mx = sqrt(prime);

void Solve() {
	int i;
	long long aux = prime, largestPrime = 0;
	for (i = 2; i < mx; i++) {
		while ((aux % i) == 0) {
			aux /= i;
			if (largestPrime < i) {
				largestPrime = i;
			}
		}
	}
	if (largestPrime < aux) {
		largestPrime = aux;
	}
	cout << largestPrime << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}