#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#include<vector>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void Solve() {
    ll a, d, g, i, k, t, x, y;
    while (cin >> g >> t >> a >> d) {
        if ((g+t+a+d) == -4) return;
        x = g*((t*(t-1))/2);
        k = (g*a)+d;
        for (i = 1; i < k; i <<= 1) {}
        x += (i-1);
        y = i-k;
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, x, y);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
