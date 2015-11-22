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
    int rows, cols, p, i, r, c;
    bool spc;
    cin >> rows >> cols >> p;
    spc = false;
    for (i = 0; i < p; i++) {
        cin >> r >> c;
        if (spc) {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << (cols*(r-1)+c);
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
