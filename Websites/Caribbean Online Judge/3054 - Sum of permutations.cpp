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
const int MOD = 1000003;
ull dp[MAX];

void FillDp() {
    int i;
    dp[1] = 1;
    for (i = 2; i < MAX; i++) dp[i] = (1+(i*dp[i-1]))%MOD;
}

void Solve() {
    int i, n, t;
    FillDp();
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
