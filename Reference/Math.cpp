#include<bitset>
#include<cmath>
#include<vector>
using namespace std;

const int MAX = 1000;
int fexponents[MAX];
bitset<MAX> sieve;
vector<int> primes;

// Binary exponentiation
// (a^b)%mod
int BExponentiation(int a, int b, int mod) {
    int result = 1;
    for (; b; b >>= 1) {
        if (b & 1) result = (result*a)%mod;
        a = (a*a)%mod;
    }
    return result;
}

// Binary multiplication
// (a*b)%mod
int BMultiplication(int a, int b, int mod) {
    int result = 0;
    for (; b; b >>= 1) {
        if (b & 1) result = (result+a)%mod;
        a = (a+a)%mod;
    }
    return result;
}

int CreatePrimes() {
    int i, j, sroot;
    sieve.set();
    sieve[0] = false;
    sieve[1] = false;
    sroot = sqrt(MAX-1);
    for (i = 2; i <= sroot; i += 1) {
        if (sieve[i]) {
            for (j = (i*i); j < MAX; j += i) sieve[j] = false;
        }
    }
}

void ExtractPrimes() {
    int i;
    for (i = 0; i < MAX; i++) {
        if (sieve[i]) primes.push_back(i);
    }
}

void FExponents(int n) {
    int i, j;
    for (i = 0; i < primes.size(); i++) {
        if (n < primes[i]) return;
        j = primes[i];
        while (j <= n) {
            fexponents[primes[i]] += (n/j);
            j *= primes[i];
        }
    }
}

int main() {
    return 0;
}
