#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 101;
const int t = 0;
const int l = 1;
const int tl = 2;
vector<string> a;
vector<string> b;
int lcs[mx][mx];
int from[mx][mx];
stack<string> words;

void LCS() {
    int i, j;
    for (i = 1; i <= a.size(); i++) {
        for (j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                lcs[i][j] = lcs[i-1][j-1]+1;
                from[i][j] = tl;
            } else {
                if (lcs[i-1][j] <= lcs[i][j-1]) {
                    lcs[i][j] = lcs[i][j-1];
                    from[i][j] = l;
                } else {
                    lcs[i][j] = lcs[i-1][j];
                    from[i][j] = t;
                }
            }
        }
    }
}

void GetWords(int r, int c) {
    if ((r == 0) || c == 0) return;
    if (from[r][c] == tl) {
        words.push(a[r-1]);
        GetWords(r-1, c-1);
    } else {
        if (from[r][c] == t) {
            GetWords(r-1, c);
        } else {
            GetWords(r, c-1);
        }
    }
}

void Solve() {
    string s;
    bool aux;
    while (cin >> s) {
        while (s  != "#") {
            a.push_back(s);
            cin >> s;
        }
        cin >> s;
        while (s != "#") {
            b.push_back(s);
            cin >> s;
        }
        LCS();
        GetWords(a.size(), b.size());
        aux = false;
        if (words.size() > 0) {
            while (!words.empty()) {
                if (aux) cout << ' ';
                aux = true;
                cout << words.top();
                words.pop();
            }
            cout << '\n';
        }
        a.clear();
        b.clear();
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
