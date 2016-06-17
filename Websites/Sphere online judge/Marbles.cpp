#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int MAX = 1000001;
int fexponents[MAX];
bitset<MAX> sieve;
vector<int> primes;

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

ull NCK(int n, int k) {
    ull i, result;
    FExponents(n-k);
    FExponents(k);
    for (i = 1; i <= n; i++) fexponents[i] *= -1;
    FExponents(n);
    result = 1;
    for (i = 1; i <= n; i++) {
        while (fexponents[i]) {
            result *= i;
            fexponents[i]--;
        }
    }
    return result;
}

void solve() {
    int i, k, n, t;
    CreatePrimes();
    ExtractPrimes();
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> k;
        cout << NCK((n-1), (k-1)) << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
