#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int m, n;
    bool spc;
    cin >> m >> n;
    if (m > n)  {
        swap(m, n);
    }
    spc = false;
    for (; m <= n; m++) {
        if (spc) {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << m;
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
