#include <algorithm>
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
	int i, j, lmt = sqrt(mx);
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

void CreateNumbers() {
	int i, j, k, a, b, c;
	for (i = 0; ((i < primes.size()) && ((a = pow(primes[i], 2)) < mx)); i++) {
		for (j = 0; ((j < primes.size()) && ((b = a + pow(primes[j], 3)) < mx)); j++) {
			for (k = 0; (k < primes.size() && ((c = b + pow(primes[k], 4)) < mx)); k++) {
				if (c < mx) {
					numbers.push_back(c);
				}
			}
		}
	}
}

void Solve() {
	int i, count = 1;
	sort(numbers.begin(), numbers.end());
	for (i = 1; i < numbers.size(); i++) {
		if (numbers[i] != numbers[i-1]) {
			count++;
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
	CreateNumbers();
	Solve();
	return 0;
}
