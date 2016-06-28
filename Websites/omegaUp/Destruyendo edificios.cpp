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

const int MAX = 1000002;
ull s[MAX][2];

void Solve() {
    ull answer, height, i, j, n;
    cin >> n;
    i = 1;
    answer = 0;
    for (j = 1; j <= (n+1); j++) {
        height = 0;
        if (j <= n) cin >> height;
        s[i][0] = j;
        s[i][1] = height;
        while ((0 < i) && (s[i][1] <= s[i-1][1])) {
            answer = max(answer, ((j-s[i-1][0])*s[i-1][1]));
            s[i-1][1] = s[i][1];
            i--;
        }
        i++;
    }
    cout << answer << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
