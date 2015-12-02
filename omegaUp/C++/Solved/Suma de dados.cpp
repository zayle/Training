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
int dice[mx];

void Solve() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> dice[i];
    }
    sort(dice, (dice+n));
    cout << (dice[0]+dice[1]) << '\n';
    cout << (dice[n-2]+dice[n-1]) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
