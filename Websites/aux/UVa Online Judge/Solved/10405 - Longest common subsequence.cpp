#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1001;
int dp[mx][mx];

void Solve() {
    string a, b;
    int i, j;
    while (getline(cin, a) && getline(cin, b)) {
        for (i = 1; i <= a.size(); i++) {
            for (j = 1; j <= b.size(); j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[a.size()][b.size()] << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
