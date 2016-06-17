#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
using namespace std;

const int MAX = 1000001;
ll MOD = 10000000000;
bitset<MAX> sieve;
ll backup[MAX];

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

void solve() {
    int i, n, t;
    CreatePrimes();
    backup[1] = 1;
    for (i = 2; i < MAX; i++) {
        backup[i] = (sieve[i] ? (backup[i-1]*i) : backup[i-1])%MOD;
    }
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        printf(((n < 31) ? "%lld\n" : "%010lld\n"), backup[n]);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
