#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, t, i;
    cin >> n >> t;
    if ((n == 1) && (t == 10)) {
        cout << -1 << '\n';
    } else {
        cout << t;
        for (i = log10(t)+1; i < n; i++) {
            cout << 0;
        }
        cout << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
