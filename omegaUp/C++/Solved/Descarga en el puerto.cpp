#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
int ids[mx], sz;

void Solve() {
    char c;
    int id, cnt, i;
    while (cin >> c) {
        if (c == 'D') {
            cin >> id;
            ids[sz++] = id;
        } else if (c == 'P')  {
            cin >> id;
            cnt = 0;
            for (i = (sz-1); i >= 0; i--) {
                if (ids[i] != id) {
                    cnt++;
                } else {
                    break;
                }
            }
            cout << cnt << '\n';
        } else {
            sz--;
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
