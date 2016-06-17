#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
using namespace std;

vector<int> digits;

void solve() {
    int i, j, n, product;
    cin >> n;
    for (i = n; 0 < i; i--) {
        j = i;
        while (j > 0) {
            digits.push_back(j%10);
            j /= 10;
        }
    }
    reverse(digits.begin(), digits.end());
    for (i = 0; i < digits.size(); i++) {
        product = digits[i];
        for (j = i+1; product < n; j++) product = (10*product)+digits[j];
        if (product == n) break;
    }
    cout << (i+1) << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
