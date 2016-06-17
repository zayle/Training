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
int fexponents[MAX], letters[26];
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
    ll i, j;
    for (i = 0; i < primes.size(); i++) {
		if (n < primes[i]) return;
        j = primes[i];
        while (j <= n) {
            fexponents[primes[i]] += (n/j);
            j *= primes[i];
        }
    }
}

void clear() {
	fill(letters, (letters+26), 0);
	fill(fexponents, (fexponents+MAX), 0);
}

void restFExponents(int n) {
    ll i, j;
    for (i = 0; i < primes.size(); i++) {
		if (n < primes[i]) return;
        j = primes[i];
        while (j <= n) {
            fexponents[primes[i]] -= (n/j);
            j *= primes[i];
        }
    }
}

void solve() {
    CreatePrimes();
	ExtractPrimes();
    int answer, i, j, t;
	string s;
    cin >> t;
    for (i = 0; i < t; i++) {
		clear();
        cin >> s;
        for (j = 0; j < s.size(); j++) letters[s[j]-'a']++;
		FExponents(s.size());
        for (j = 0; j < 26; j++) restFExponents(letters[j]);
		while ((0 < fexponents[2]) && (0 < fexponents[5])) {
        	fexponents[2]--;
        	fexponents[5]--;
		}
		answer = 1;
        for (j = 0; j < primes.size(); j++) {
			if (s.size() < primes[j]) break;
            while (0 < fexponents[primes[j]]) {
				answer = (answer*(primes[j]%10))%10;
				fexponents[primes[j]]--;
			}
        }
		cout << answer << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
