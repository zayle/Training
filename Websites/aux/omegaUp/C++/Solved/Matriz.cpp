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

const int mx = 50;
int numbers[mx][mx];

void Solve() {
    int rows, cols, r, c;
    bool spc;
    cin >> rows >> cols;
    for (r = 0; r < cols; r++) {
        for (c = 0; c < cols; c++) {
            cin >> numbers[r][c];
        }
    }
    for (r = (rows-1); r >= 0; r--) {
        spc = false;
        for (c = 0; c < cols; c++) {
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
