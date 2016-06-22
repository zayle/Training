#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 999;
int lps[mx][mx];
string s;

int LPS() {
    int sz, i, j;
    for (sz = 0; sz < s.size(); sz++) {
        for (i = 0; i+sz < s.size(); i++) {
            j = i+sz;
            if (sz == 0) {
                lps[i][j] = 1;
            } else {
                if (s[i] == s[j]) {
                    lps[i][j] = 2;
                    if (i+1 <= j-1) lps[i][j] += lps[i+1][j-1];
                } else {
                    lps[i][j] = max(lps[i][j-1], lps[i+1][j]);
                }
            }
        }
    }
}

void Solve() {
    int t, i;
    cin >> t;
    getline(cin, s);
    for (i = 0; i < t; i++) {
        getline(cin, s);
        LPS();
        cout << lps[0][s.size()-1] << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
