#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
vector<int> primes;

bool isPrime(int a) {

    int i, sr = sqrt(a);
    for (i = 0; primes[i] <= sr; i++) {
        if ((a%primes[i]) == 0) {
            return false;
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

int GetChainLength(int a) {
    int i, sum = 0, aux = 0, length = 0, j = 0;
    for (i = 0; i < a; i++) {
        sum += primes[i];
        aux++;
        while (sum > primes[a]) {
            sum -= primes[j++];
            aux--;
        }
        if (sum == primes[a]) {
            if (length < aux) {
                length = aux;
            }
        }
    }
    return length;
}

void Solve() {
    int i, aux, maxChain = 0, prime;
    for (i = 0; i < primes.size(); i++) {
        aux = GetChainLength(i);
        if (maxChain < aux) {
            maxChain = aux;
            prime = primes[i];
        }
    }
    cout << prime << ' ' << maxChain << '\n';
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
