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

const int MAX = 1025;
bitset<MAX> flags;

void solve() {
    int answer, i, j, k, m, n, t;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> m;
        flags.reset();
        for (j = 0; j < m; j++) {
            cin >> k;
            flags[k] = true;
        }
        answer = 0;
        while (n) {
            for (j = 2; j <= (1<<n); j += 2) {
                if (flags[j-1] && flags[j]) {
                    flags[j>>1] = true;
                } else if (!flags[j-1] && !flags[j]) {
                    flags[j>>1] = false;
                } else {
                    flags[j>>1] = false;
                    answer++;
                }
            }
            n--;
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
