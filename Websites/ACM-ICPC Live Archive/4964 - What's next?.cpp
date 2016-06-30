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
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (!a && !b && !c) return;
        if ((b-a) == (c-b)) {
            cout << "AP " << (c+(b-a)) << '\n';
        } else {
            cout << "GP " << (c*(b/a)) << '\n';
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
