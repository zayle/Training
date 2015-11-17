#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
const int mod = 1000000007;
int black[mx];
int white[mx];

void Solve() {
    int n, i, aux, answer;
    cin >> n;
    // It starts with white
    black[0] = 0;
    white[0] = 1;
    for (i = 1; i < n; i++) {
        black[i] = (white[i-1])%mod;
        white[i] = (black[i-1]+white[i-1])%mod;
    }
    answer = (black[n-1]+white[n-1])%mod;
    // It starts with black
    black[0] = 1;
    white[0] = 0;
    for (i = 1; i < n; i++) {
        black[i] = (white[i-1])%mod;
        white[i] = (black[i-1]+white[i-1])%mod;
    }
    answer = (answer+white[n-1])%mod;
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
    Solve();
	return 0;
}
