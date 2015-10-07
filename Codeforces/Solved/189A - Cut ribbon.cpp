#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 40001;
int dp[mx];

int get(int a) {
    if ((a < 0) || ((a > 0) && (dp[a] == 0))) return -1;
    return dp[a];
}

void Solve() {
    int n, a, b, c, i;
    cin >> n >> a >> b >> c;
    for (i = 1; i <= n; i++) {
        dp[i] = max(dp[i], get(i-a)+1);
        dp[i] = max(dp[i], get(i-b)+1);
        dp[i] = max(dp[i], get(i-c)+1);
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
