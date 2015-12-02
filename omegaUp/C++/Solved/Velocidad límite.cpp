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
    int n, sum, aux, i, s, t;
    cin >> n;
    sum = 0;
    aux = 0;
    for (i = 0; i < n; i++) {
        cin >> s >> t;
        sum += (s*(t-aux));
        aux = t;
    }
    cout << sum << " miles" << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
