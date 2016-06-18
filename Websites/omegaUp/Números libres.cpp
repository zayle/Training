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

ull GCD(ull a, ull b) {
    if (a < b) swap(a, b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ull a, b, i, t;
    string answer;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> a >> b;
        answer = "SI\n";
        if (1 < GCD(a, b)) answer = "NO\n";
        cout << answer;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
