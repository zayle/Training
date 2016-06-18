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

const int MAX = 65;
int primes[18] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
ull answers[MAX];
vector<int> factors;
vector<ull> candidates;


void extractFactors(int n) {
    int i;
    factors.clear();
    for (i = 0; i < 18; i++) {
        while (!(n%primes[i])) {
            factors.push_back(primes[i]);
            n /= primes[i];
        }
    }
}

ull exponentiation(int a, int b) {
    ull result = 1;
    while (b--) result *= a;
    return result;
}

void addCandidates(int n) {
    ull candidate, exponent, f, i, j, p;
    for (i = 0; i < (1<<(n-1)); i++) {
        exponent = 1;
        candidate = 1;
        p = 0;
        for (j = 0; j < (n-1); j++) {
            exponent *= factors[j];
            if ((i>>j)&1) {
                candidate *= exponentiation(primes[p++], (exponent-1));
                exponent = 1;
            }
        }
        exponent *= factors[j];
        candidate *= exponentiation(primes[p], (exponent-1));
        candidates.push_back(candidate);
    }
}

void createAnswers() {
    int i, j;
    answers[1] = 1;
    for (i = 2; i < MAX; i++) {
        extractFactors(i);
        candidates.clear();
        do {
            addCandidates(factors.size());
        } while (next_permutation(factors.begin(), factors.end()));
        sort(candidates.begin(), candidates.end());
        answers[i] = candidates[0];
    }
}

void solve() {
    int i, n, t;
    createAnswers();
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        cout << answers[n] << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
