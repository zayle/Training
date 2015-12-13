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
    int n, aux, i, a, b;
    cin >> n >> aux;
    a = aux;
    b = aux;
    for (i = 1; i < n; i++) {
        cin >> aux;
        a = min(a, aux);
        b = max(b, aux);
    }
    cout << (((b-a)+1)-n) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
