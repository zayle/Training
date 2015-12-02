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
    string s;
    int i;
    bool spc;
    getline(cin, s);
    spc = false;
    for (i = 0; i < s.size(); i++) {
        if ((s[i] == '0') || (s[i] == '1')) {
            if (spc) {
                cout << ' ';
            } else {
                spc = true;
            }
            cout << (s[i] == '0');
        }
    }
    cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
