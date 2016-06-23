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
int dp[MAX][MAX];

int GetFromDp(int a, int b) {
    if (b < a) return 0;
    return dp[a][b];
}

int DP(string s, int k) {
    int answer, i, j, l;
    answer = 1;
    for (i = 1; i < s.size(); i++) {
        for (j = 0; (j+i) < s.size(); j++) {
            l = j+i;
            dp[j][l] = GetFromDp((j+1), (l-1));
            if (s[j] != s[l]) dp[j][l]++;
            if (dp[j][l] <= k) answer = max((i+1), answer);
        }
    }
    return answer;
}

void solve() {
    int i, k, t;
    string s;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> s >> k;
        cout << DP(s, k) << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}
