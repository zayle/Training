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

const int MAX = 12;
int dp[4096][3], times[3][MAX];

int DP(int n) {
    int answer, count, i, j, k;
    answer = 0;
    for (i = 1; i < (1<<n); i++) {
        dp[i][0] = 3360;
        dp[i][1] = 3360;
        dp[i][2] = 3360;
        count = 0;
        for (j = 0; j < n; j++) {
            if (i&(1<<j)) {
                k = i-(1<<j);
                dp[i][0] = min((dp[k][1]+times[0][j]), dp[i][0]);
                dp[i][0] = min((dp[k][2]+times[0][j]), dp[i][0]);
                dp[i][1] = min((dp[k][0]+times[1][j]), dp[i][1]);
                dp[i][1] = min((dp[k][2]+times[1][j]), dp[i][1]);
                dp[i][2] = min((dp[k][0]+times[2][j]), dp[i][2]);
                dp[i][2] = min((dp[k][1]+times[2][j]), dp[i][2]);
                count++;
            }
        }
        if (dp[i][0] <= 280) answer = max(count, answer);
        if (dp[i][1] <= 280) answer = max(count, answer);
        if (dp[i][2] <= 280) answer = max(count, answer);
    }
    return answer;
}

void solve() {
    int i, j, k, n, t;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        for (j = 0; j < n; j++) cin >> times[0][j];
        for (j = 0; j < n; j++) cin >> times[1][j];
        for (j = 0; j < n; j++) cin >> times[2][j];
        cout << DP(n) << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
