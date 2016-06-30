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
    int a, b, c, d, e, f, i, j, n;
    i = 1;
    while (cin >> n) {
        if (!n) return;
        cin >> a >> b >> c;
        a = b;
        c += b;
        for (j = 1; j < n; j++) {
            cin >> d >> e >> f;
            d += min(a, b);
            e += min(min(a, b), min(c, d));
            f += min(min(b, c), e);
            a = d;
            b = e;
            c = f;
        }
        cout << i << ". " << b << '\n';
        i++;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
