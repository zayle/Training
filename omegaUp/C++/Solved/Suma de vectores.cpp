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

const int mx = 100;
int sums[mx];

void Solve() {
    int n, i, aux;
    bool spc;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> sums[i];
    }
    spc = false;
    for (i = 0; i < n; i++) {
        cin >> aux;
        sums[i] += aux;
        if (spc) {
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
