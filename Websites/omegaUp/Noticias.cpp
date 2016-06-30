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
int parents[MAX], sums[MAX];

int Root(int a) {
    if (parents[a] == a) return a;
    return (parents[a] = Root(parents[a]));
}

void Initialize() {
    int i;
    for (i = 0; i < MAX; i++) parents[i] = i;
    fill(sums, (sums+MAX), 1);
}

void Solve() {
    char c;
    int i, j, n, p, x, y, rx, ry;
    Initialize();
    cin >> n >> i;
    for (j = 0; j < i; j++) {
        cin >> c;
        if (c == 'A') {
            cin >> x >> y;
            rx = Root(x);
            ry = Root(y);
            if (rx != ry) {
                sums[ry] += sums[rx];
                parents[rx] = ry;
            }
        } else {
            cin >> p;
            cout << sums[Root(p)] << '\n';
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
