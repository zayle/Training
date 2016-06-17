#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
using namespace std;

const int MAX = 50000;
bitset<MAX> sieve;
vector<int> factors;
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

void addFactors(ll n) {
    int i;
    for (i = 0; i < primes.size(); i++) {
        while (!(n%primes[i])) {
            factors.push_back(primes[i]);
            n /= primes[i];
        }
        if (n == 1) return;
    }
    if (1 < n) factors.push_back(n);
}

void solve() {
    ll a, b, i;
    string answer;
    CreatePrimes();
    ExtractPrimes();
    while (cin >> a >> b) {
        factors.clear();
        addFactors(a);
        addFactors(b);
        sort(factors.begin(), factors.end());
        answer = "YES\n";
        for (i = 1; i < factors.size(); i++) {
            if (factors[i] == factors[i-1]) answer = "NO\n";
        }
        cout << answer;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
