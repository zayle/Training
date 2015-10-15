#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100000;
int dpCols[mx];
int dpRows[mx];
int rows, cols;

int GetDp(int i, int dp[mx]) {
    if (i < 0) return 0;
    return dp[i];
}

int Dp(int dp[mx], int lmt) {
    int i;
    for (i = 0; i < lmt; i++) {
        dp[i] = max(GetDp(i-1, dp), dp[i]+GetDp(i-2, dp));
    }
    return dp[lmt-1];
}

void Solve() {
    int r, c;
    while ((cin >> rows >> cols) && (rows|cols)) {
        for (r = 0; r < rows; r++) {
            for (c = 0; c < cols; c++) {
                cin >> dpCols[c];
            }
            dpRows[r] = Dp(dpCols, cols);
        }
        Dp(dpRows, rows);
        cout << dpRows[rows-1] << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
