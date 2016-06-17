#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
vector<int> primes;
int sums[mx + 1];
bool used[mx + 1];

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
	for (i = 3; i <= mx; i += 2) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
}

int GetSumOfDivisors(int a) {
	int i, sr = sqrt(a), exponent, prime, sum = 1;
	for (i = 0; primes[i] <= sr; i++) {
		exponent = 1;
		prime = primes[i];
		while ((a % prime) == 0) {
			exponent++;
			a /= prime;
		}
		sum *= ((pow(prime, exponent) - 1) / (prime - 1));
		sr = sqrt(a);
	}
	if (a > 1) {
		sum *= (1 + a);
	}
	return sum;
}

void CreateSums() {
	int i;
	for (i = 1; i <= mx; i++) {
		sums[i] = GetSumOfDivisors(i) - i;
	}
}

void Clear(int a) {
	while (used[a]) {
		used[a] = false;
		a = sums[a];
		if (a > mx) {
			return;
		}
	}
}

int GetCycleCount(int a) {
	int count = 0, aux = a;
	while (!used[aux]) {
		used[aux] = true;
		count++;
		aux = sums[aux];
		if (aux > mx) {
			return -1;
		}
	}
	Clear(a);
	if (aux == a) {
		return count;
	} else {
		return -1;
	}
}

void Solve() {
	int i, count, minNumber = mx, maxCount = 0;
	for (i = 0; i <= mx; i++) {
		if (!used[i]) {
			count = GetCycleCount(i);
			if (count > -1) {
				if (maxCount < count) {
					maxCount = count;
					minNumber = i;
				}
			}
		}
	}
	cout << minNumber << ' ' << maxCount << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreatePrimes();
	CreateSums();
	Solve();
	return 0;
}