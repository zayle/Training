#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 2001;
const int inf = pow(mx, 2);
int dp[mx];

int get(int a) {
    if (a < 0) return inf;
    return dp[a];
}

void Solve() {
    int n, m, a, b, i, mn;
    mn = inf;
    cin >> n >> m >> a >> b;
    for (i = 1; i <= (n+m)-1; i++) {
        dp[i] = min(get(i-1)+a, get(i-m)+b);
        if (n <= i) {
            mn = min(mn, dp[i]);
        }
    }
    cout << mn << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
