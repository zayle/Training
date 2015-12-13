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
    int n, i, k, sum, j, o;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> k;
        sum = 0;
        for (j = 0; j < k; j++) {
            cin >> o;
            sum += (o-1);
        }
        cout << (sum+1) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
