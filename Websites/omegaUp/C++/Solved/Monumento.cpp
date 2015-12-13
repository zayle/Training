#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000001, mod = 1000000;
int dp[mx];

void Solve() {
    int n, i;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = (dp[i-2]+dp[i-1])%mod;
    }
    cout << dp[n] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
