#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 10000;
long long dp[mx];

void Solve() {
    int n, k, i, j;
    cin >> n >> k;
    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
            } else {
                break;
            }
        }
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
