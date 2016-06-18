#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
using namespace std;

vector<int> divisors;

int GCD(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int CreateDivisors(int n) {
    int i, sroot;
    sroot = sqrt(n);
    for (i = 1; i <= sroot; i++) {
        if (!(n%i)) {
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }
}

void solve() {
    int a, answer, b, gcd, h, i, j, l, n;
    cin >> a >> b >> n;
    CreateDivisors(GCD(a, b));
    sort(divisors.begin(), divisors.end());
    reverse(divisors.begin(), divisors.end());
    for (i = 0; i < n; i++) {
        cin >> l >> h;
        answer = -1;
        for (j = 0; j < divisors.size(); j++) {
            if ((l <= divisors[j]) && (divisors[j] <= h)) {
                answer = divisors[j];
                break;
            }
        }
        cout << answer << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
