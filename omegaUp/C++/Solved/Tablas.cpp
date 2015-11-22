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

void Solve() {
    int n, i, aux, j;
    bool spc;
    cin >> n;
    spc = false;
    for (i = 0; i < n; i++) {
        cin >> aux;
        if (spc) {
            cout << '\n';
        } else {
            spc = true;
        }
        for (j = 1; j <= 10; j++) {
            cout << aux << 'x' << j << '=' << (aux*j) << '\n';
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
