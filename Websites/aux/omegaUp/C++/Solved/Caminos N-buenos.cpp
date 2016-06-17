#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const long long mx = 300;
const long long mod = 10000000007;
long long dp[mx+1][mx+1][mx];

void Solve() {
    long long n, r, c, aux, m;
    cin >> n;
    dp[0][1][0] = 1;
	for (r = 1; r <= n; r++) {
        for (c = 1; c <= n; c++) {
            cin >> aux;
            aux = aux%n;
            for (m = 0; m < n; m++) {
                dp[r][c][m] += dp[r-1][c][((n-aux)+m)%n];
                dp[r][c][m] += dp[r][c-1][((n-aux)+m)%n];
                dp[r][c][m] = dp[r][c][m]%mod;
            }
        }
	}
	cout << dp[n][n][0] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
