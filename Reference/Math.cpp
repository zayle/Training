#include<bitset>
#include<vector>
using namespace std;

const int MAX = 1000;
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

int main() {
    return 0;
}
