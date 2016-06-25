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

const int MAX = 1000;
ull serials[MAX];

ull GCD(ull a, ull b) {
    if (a < b) swap(a, b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void Solve() {
    bool impossible;
    ull a, aux, b, c, gcd, i, j, k, maxb, t;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> c;
        maxb = 0;
        impossible = true;
        for (j = 0; j < c; j++) {
            a = 0;
            for (k = 0; k < 9; k++) {
                cin >> aux;
                a += aux;
            }
            cin >> b;
            maxb = max(maxb, b);
            if (a != b) impossible = false;
            serials[j] = abs(a-b);
        }
        if (!impossible) {
            gcd = serials[0];
            for (j = 1; j < c; j++) gcd = GCD(gcd, serials[j]);
            impossible = (gcd == 1);
        }
        if (!impossible) impossible = !(maxb < gcd);
        if (impossible) cout << "impossible\n";
        else cout << gcd << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
