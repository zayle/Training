#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 500001;
long long dp[mx];

void Solve() {
    long long n, i, aux;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> aux;
        dp[aux]++;
    }
    for (i = 2; i < mx; i++) {
        aux = dp[i];
        dp[i] = max(dp[i-1], dp[i-2]+(i*aux));
    }
    cout << dp[mx-1] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
