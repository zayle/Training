#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int m, a, b;
    bool spc;
    cin >> m;
    spc = false;
    for (a = 1, b = 1; b < m; swap((a += b), b)) {
        if (spc) {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << b;
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
