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

const int mx = 65;
ll sums[mx];

void Solve() {
    int n, i;
    bool spc;
    cin >> n;
    sums[1] = 1;
    sums[2] = 1;
    sums[3] = 2;
    for (i = 4; i <= mx; i++) {
        sums[i] = sums[i-3]+sums[i-2]+sums[i-1];
    }
    spc = false;
    for (i = 1; i <= n; i++) {
        if (spc)  {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << sums[i];
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
