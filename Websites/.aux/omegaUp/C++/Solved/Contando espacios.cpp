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
    string s;
    int i, cnt;
    while (getline(cin, s)) {
        cnt = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
