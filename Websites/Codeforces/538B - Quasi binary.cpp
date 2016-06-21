#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000001;
vector<int> quasiBinaries;
int dp[mx];
int vals[mx];

int GetDecimal(int a) {
    if (a == 0) return 0;
    return 10*GetDecimal(a/2)+(a%2);
}

void CreateQuasiBinaries(int n) {
    int i, lmt;
    lmt = pow(2, 6);
    for (i = 1; i <= lmt; i++) {
        quasiBinaries.push_back(GetDecimal(i));
        if (n < quasiBinaries[i-1]) {
            break;
        }
    }
}

int GetDp(int a) {
    if (a < 0) return mx;
    return dp[a];
}

void Solve() {
    int n, i, j;
    cin >> n;
    CreateQuasiBinaries(n);
    for (i = 1; i <= n; i++) {
        dp[i] = GetDp(i-1)+1;
        vals[i] = 1;
        for (j = 1; j < quasiBinaries.size(); j++) {
            if (GetDp(i-quasiBinaries[j])+1 < dp[i]) {
                dp[i] = GetDp(i-quasiBinaries[j])+1;
                vals[i] = quasiBinaries[j];
            }
        }
    }
    cout << dp[n] << '\n' << vals[n];
    i = n-vals[n];
    while (i != 0) {
        cout << ' ' << vals[i];
        i -= vals[i];
    }
    cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
