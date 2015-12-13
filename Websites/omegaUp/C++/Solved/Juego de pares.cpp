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

int cnts[2];

void Solve() {
    int i, aux;
    for (i = 0; i < 10; i++) {
        cin >> aux;
        cnts[i/5] += (1-(aux%2));
    }
    cout << cnts[0] << '\n';
    cout << cnts[1] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
