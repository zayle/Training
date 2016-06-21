#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 2000;
int lps[mx][mx][2];
bool specials[mx];
string s;

void Clear(int a) {
    int i;
    for (i = 0; i < a; i++) {
        specials[i] = false;
    }
}

void LPS() {
    int sz, i, j;
    for (sz = 0; sz < s.size(); sz++) {
        for (i = 0; i+sz < s.size(); i++) {
            j = i+sz;
            if (sz == 0) {
                lps[i][j][0] = 1;
                lps[i][j][1] = specials[i];
            } else {
                if ((s[i] == s[j]) && specials[i] && specials[j]) {
                    lps[i][j][0] = 2;
                    lps[i][j][1] = 2;
                    if (i+1 <= j-1) {
                        lps[i][j][0] += lps[i+1][j-1][0];
                        lps[i][j][1] += lps[i+1][j-1][1];
                    }
                } else {
                    if (lps[i][j-1][1] < lps[i+1][j][1]) {
                        lps[i][j][0] = lps[i+1][j][0];
                        lps[i][j][1] = lps[i+1][j][1];
                    } else if (lps[i][j-1][1] == lps[i+1][j][1]) {
                        lps[i][j][0] = max(lps[i][j-1][0], lps[i+1][j][0]);
                        lps[i][j][1] = lps[i][j-1][1];
                    } else  {
                        lps[i][j][0] = lps[i][j-1][0];
                        lps[i][j][1] = lps[i][j-1][1];
                    }
                    if (s[i] == s[j]) {
                        if (specials[i] || specials[j]) {
                            if (i+1 <= j-1) {
                                if (lps[i][j][1] < lps[i+1][j-1][1]+1) {
                                    lps[i][j][0] = lps[i+1][j-1][0]+2;
                                    lps[i][j][1] = lps[i+1][j-1][1]+1;
                                } else if (lps[i][j][1] == lps[i+1][j-1][1]+1) {
                                    if (lps[i][j][0] < lps[i+1][j-1][0]+2) {
                                        lps[i][j][0] = lps[i+1][j-1][0]+2;
                                    }
                                }
                            } else {
                                lps[i][j][0] = 2;
                                lps[i][j][1] = 1;
                            }
                        } else {
                            if (i+1 <= j-1) {
                                if (lps[i][j][1] < lps[i+1][j-1][1]) {
                                    lps[i][j][0] = lps[i+1][j-1][0]+2;
                                    lps[i][j][1] = lps[i+1][j-1][1];
                                } else if (lps[i][j][1] == lps[i+1][j-1][1]) {
                                    if (lps[i][j][0] < lps[i+1][j-1][0]+2) {
                                        lps[i][j][0] = lps[i+1][j-1][0]+2;
                                    }
                                }
                            } else {
                                lps[i][j][0] = 2;
                                lps[i][j][1] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Solve() {
    int n, i, special;
    while (cin >> s) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> special;
            specials[special-1] = true;
        }
        LPS();
        cout << lps[0][s.size()-1][0] << '\n';
        Clear(s.size());
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
