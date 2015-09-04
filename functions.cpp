#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int mx = 1000;
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

void CreatePrimes() {
	int i;
	primes.push_back(2);
	for (i = 3; i < mx; i += 3) {
		if (isPrime(i)) {
			primes.push_back(i);
;		}
	}
}


int GetSumOfDivisors(int a) {
	int i, sr = sqrt(a), exponent, prime, sum = 1;
	for (i = 0; primes[i] <= sr; i++) {
		exponent = 1;
		prime = primes[i];
		while ((a % prime) == 0) {cout << prime << ' ';
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

int main() {
	return 0;
}