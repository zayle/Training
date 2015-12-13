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

void Solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "Nivel Optimo" << '\n';
    } else {
        if (a < b) {
            cout << 1 << ' ' << (b-a) << '\n';
        } else {
            cout << 2 << ' ' << (a-b) << '\n';
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
