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

const int MAX = 2000;
const int MOD = 1000000007;
ull deltas[MAX], numbers[MAX];

ull BExponentiation(ull a, ull b, ull mod) {
    ull result = 1;
    for (; b; b >>= 1) {
        if (b & 1) result = (result*a)%mod;
        a = (a*a)%mod;
    }
    return result;
}

void FillDeltas(int n, int k) {
    int i;
    deltas[0] = 1;
    for (i = 1; i < n; i++) {
        deltas[i] = (deltas[i-1]*(k+i))%MOD;
        deltas[i] = (deltas[i]*BExponentiation(i, (MOD-2), MOD))%MOD;
    }
}

void Solve() {
    int aux, i, j, n, k, sum;
    cin >> n >> k;
    FillDeltas(n, (k-1));
    for (i = 0; i < n; i++) cin >> numbers[i];
    for (i = 0; i < n; i++) {
        sum = numbers[i];
        for (j = 0; j < i; j++) sum = (sum+((numbers[j]*deltas[i-j])%MOD))%MOD;
        if (i != 0) cout << ' ';
        cout << sum;
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
