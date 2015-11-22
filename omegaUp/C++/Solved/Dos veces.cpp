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
    while (getline(cin, s)) {
        for (i = 0; i < s.size(); i++) {
            if (('a' <= s[i]) && (s[i] <= 'z')) {
                cout << char(s[i]-32);
            } else {
                cout << s[i];
            }
        }
        cout << '\n';
        for (i = 0; i < s.size(); i++) {
            if (('A' <= s[i]) && (s[i] <= 'Z')) {
                cout << char(s[i]+32);
            } else {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
