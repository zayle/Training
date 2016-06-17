#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
using namespace std;

const int MAX = 64000;
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

bool isPrime(ll n) {
    int i;
    if (!n || (n == 1)) return false;
    for (i = 0; i < primes.size(); i++) {
        if (n <= primes[i]) break;
        if (!(n%primes[i])) return false;
    }
    return true;
}

void solve() {
    ll cases, i, j, n;
    CreatePrimes();
    ExtractPrimes();
    cin >> cases;
    for (i = 0; i < cases; i++) {
        cin >> n;
        for (j = n; true; j++) {
            if (isPrime(j)) {
                cout << j << '\n';
                break;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
