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

char findChar(int n, int depth) {
    while (true) {
        if (n == 0) return '(';
        if (n == ((1<<depth)-1)) return ')';
        depth--;
        if (((1<<depth)-1) <= n) n -= ((1<<depth)-1);
    }
}

void solve() {
    ll i, k, limit, m, n;
    while (cin >> n >> k >> m) {
        if (!n && !k && !m) return;
        limit = k+m;
        for (i = k; i < limit; i++) cout << findChar(i, n);
        cout << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
