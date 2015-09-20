#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 22;
const int dpmx = pow(2, mx);
const int delta = 1000000;
int powers[mx+1], n, data[mx][mx], dp[dpmx][2];

void CreatePowers() {
    int i;
    powers[0] = 1;
    for (i = 1; i <= mx; i++) {
        powers[i] = 2*powers[i-1];
    }
}

void Load() {
    int r, c;
    cin >> n;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            cin >> data[r][c];
            data[r][c] += delta;
        }
    }
}

void Solve() {
    int lmt, i, j, aux;
    CreatePowers();
    Load();
    dp[0][1] = -1;
    lmt = pow(2, n);
    for (i = 0; i < lmt; i++) {
        for (j = 0; powers[j] <= i; j++) {
            if (i&powers[j]) {
                aux = i^powers[j];
                dp[i][1] = dp[aux][1]+1;
                dp[i][0] = max(dp[i][0], dp[aux][0]+data[dp[i][1]][j]);
            }
        }
    }
    cout << (dp[lmt-1][0]-(delta*n)) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
