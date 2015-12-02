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
    int a, b, c;
    cin >> a >> b >> c;
    if (c < a) {
        cout << "IZQUIERDA" << '\n';
    } else if (b < c) {
        cout << "DERECHA" << '\n';
    } else {
        cout << "INTERVALO" << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
