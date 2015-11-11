#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 201;
const int no = 0;
const int so = 1;
const int ea = 2;
const int we = 3;
char mp[mx][mx];

void Clear() {
    int r, c;
    for (r = 0; r < mx; r++) {
        for (c = 0; c < mx; c++) {
            mp[r][c] = '#';
        }
    }
}

void Solve() {
    int t, i, r, c, minR, maxR, minC, maxC, j, ori;
    string s;
    cin >> t;
    cout << t << '\n';
    for (i = 0; i < t; i++) {
        cin >> s;
        Clear();
        r = 100;
        c = 100;
        mp[r][c] = '.';
        minR = r;
        maxR = r;
        minC = c;
        maxC = c;
        ori = ea;
        for (j = 0; j < s.size(); j++) {
            if (s[j] == 'F') {
                if      (ori == no) r--;
                else if (ori == so) r++;
                else if (ori == ea) c++;
                else if (ori == we) c--;
            } else if (s[j] == 'R') {
                if      (ori == no) { c++, ori = ea; }
                else if (ori == so) { c--, ori = we; }
                else if (ori == ea) { r++, ori = so; }
                else if (ori == we) { r--, ori = no; }
            } else if (s[j] == 'L') {
                if      (ori == no) { c--, ori = we; }
                else if (ori == so) { c++, ori = ea; }
                else if (ori == ea) { r--, ori = no; }
                else if (ori == we) { r++, ori = so; }
            } else {
                if      (ori == no) { r++; ori = so; }
                else if (ori == so) { r--; ori = no; }
                else if (ori == ea) { c--; ori = we; }
                else if (ori == we) { c++; ori = ea; }
            }
            mp[r][c] = '.';
            if (r < minR) minR = r;
            if (maxR < r) maxR = r;
            if (c < minC) minC = c;
            if (maxC < c) maxC = c;
        }
        cout << ((maxR-minR)+3) << ' ' << ((maxC-minC)+2) << '\n';
        for (r = minR-1; r <= maxR+1; r++) {
            for (c = minC; c <= maxC+1; c++) {
                cout << mp[r][c];
            }
            cout << '\n';
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
