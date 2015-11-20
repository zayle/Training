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

const int mx = 101;
int votes[mx];

void Solve() {
    int p, n, i, a, v;
    cin >> p >> n;
    for (i = 0; i < n; i++) {
        cin >> v;
        votes[v]++;
    }
    for (i = 1; i <= p; i++) {
        cout << i << '-' << votes[i] << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
