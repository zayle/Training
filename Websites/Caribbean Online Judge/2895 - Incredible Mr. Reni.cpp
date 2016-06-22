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

ull countP(ull n, ull p) {
    ull count;
    count = 0;
    while (n) {
        count += (n/p);
        n /= p;
    }
    return count;
}

void solve() {
    ull a, answer, b, p;
    while (cin >> a >> b >> p) {
        answer = countP(b, p)-countP((a-1), p);
        printf("%llo\n", answer);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
