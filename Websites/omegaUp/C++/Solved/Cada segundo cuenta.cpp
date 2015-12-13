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
    if (a < b) {
        if ((b-a) == 1) {
            cout << "ADELANTAR 1 SEGUNDO" << '\n';
        } else {
            cout << "ADELANTAR " << (b-a) << " SEGUNDOS" << '\n';
        }
    } else {
        if ((a-b) == 1) {
            cout << "ATRASAR 1 SEGUNDO" << '\n';
        } else {
            cout << "ATRASAR " << (a-b) << " SEGUNDOS" << '\n';
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
