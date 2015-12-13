#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 51;
bool rows[mx];
bool cols[mx];

void Solve() {
    int n, nn, i, r, c;
    cin >> n;
    nn = pow(n, 2);
    for (i = 1; i <= nn; i++) {
        cin >> r >> c;
        if ((!rows[r]) && (!cols[c])) {
            rows[r] = true;
            cols[c] = true;
            if (i > 1) cout << ' ';
            cout << i;
        }
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
