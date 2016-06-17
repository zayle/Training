#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 101;
int dp[mx];

void Solve() {
    int n, i, aux, zeros, mxSum;
    cin >> n;
    zeros = 0;
    mxSum = -1;
    for (i = 1; i <= n; i++) {
        cin >> aux;
        if (aux == 1) {
            zeros++;
            aux = -1;
        } else {
            aux = 1;
        }
        dp[i] = max(dp[i-1]+aux, aux);
        mxSum = max(mxSum, dp[i]);
    }
    cout << (zeros+mxSum) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
