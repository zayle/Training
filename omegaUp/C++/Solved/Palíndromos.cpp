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
    string s, answer;
    int a, b;
    while (cin >> s) {
        answer = "P";
        for (a = 0, b = (s.size()-1); a < b; a++, b--) {
            if (s[a] != s[b]) {
                answer = "NP";
                break;
            }
        }
        cout << answer << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
