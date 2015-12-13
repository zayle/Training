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
    int h, m;
    cin >> h >> m;
    if (m < 45) {
        cout << ((h+23)%24) << ' ' << ((m+15)%60) << '\n';
    } else {
        cout << h << ' ' << (m-45) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
