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
    char c;
    int cnt;
    cnt = 0;
    while (cin >> c) {
        if (c == 'E') {
            cnt++;
        } else if (c == 'N') {
            if (cnt <= 4) {
                cnt++;
                cout << "espera" << '\n';
            } else {
                cout << "no espera" << '\n';
            }
        } else {
            cnt--;
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
