#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;
int numbers[mx][mx];

void Solve() {
    int n, r, c;
    bool spc;
    cin >> n;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            cin >> numbers[c][(n-r)-1];
        }
    }
    for (r = 0; r < n; r++) {
        spc = false;
        for (c = 0; c < n; c++) {
            if (spc) {
                cout << ' ';
            } else {
                spc = true;
            }
            cout << numbers[r][c];
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
