#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mn = 1000000;
const int mx = 101;

int C(int n, int r) {
    int i, c = 1;
    for (i = 1; i <= r; i++) {
        c *= ((n-r)+i);
        c /= i;
        if (c > mn) {
            return c;
        }
    }
    return c;
}

void Solve() {
    int n, r, count = 0;
    for (n = 1; n < mx; n++) {
        for (r = 0; r <= n; r++) {
            if(C(n, r) > mn) {
                count++;
            }
        }
    }
    cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
