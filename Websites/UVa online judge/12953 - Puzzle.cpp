#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int solsmx  = 123*122+123;
const int lmt = -1000001;
const int mx = 100;
int sols[solsmx];
bool rused[mx], cused[mx];
int vars[mx][mx];
int rsums[mx], csums[mx];
int rows, cols;

void Clear() {
    int i;
    for (i = 0; i < solsmx; i++) {
        sols[i] = lmt;
    }
}

int StringToInt(string a) {
    int rtrn = 123*int(a[0]);
    rtrn += int(a[1]);
    return rtrn;
}

void Load() {
    int r, c;
    string aux;
    Clear();
    for (r = 0; r < rows; r++) {
        rused[r] = false;
        for (c = 0; c < cols; c++) {
            cin >> aux;
            vars[r][c] = StringToInt(aux);
        }
        cin >> rsums[r];
    }
    for (c = 0; c < cols; c++) {
        cused[c] = false;
        cin >> csums[c];
    }
}

int FindRow() {
    int r, c, aux;
    for (r = 0; r < rows; r++) {
        if(!rused[r]) {
            aux = lmt;
            for (c = 0; c < cols; c++) {
                if (sols[vars[r][c]] == lmt) {
                    if (aux == lmt) {
                        aux = vars[r][c];
                    } else if (vars[r][c] != aux) {
                        break;
                    }
                }
            }
            if (c == cols) {
                if (aux != lmt) {
                    return r;
                }
            }
        }
    }
    return -1;
}

int FindColumn() {
    int c, r, aux;
    for (c = 0; c < cols; c++) {
        if (!cused[c]) {
            aux = lmt;
            for (r = 0; r < rows; r++) {
                if (sols[vars[r][c]] == lmt) {
                    if (aux == lmt) {
                        aux = vars[r][c];
                    } else if (vars[r][c] != aux) {
                        break;
                    }
                }
            }
            if (r == rows) {
                if (aux != lmt) {
                    return c;
                }
            }
        }
    }
    return -1;
}

void SolveRow(int r) {
    int c, var, count = 0;
    for (c = 0; c < cols; c++) {
        if (sols[vars[r][c]] == lmt) {
            var = vars[r][c];
            count++;
        } else {
            rsums[r] -= sols[vars[r][c]];
        }
    }
    sols[var] = rsums[r]/count;
    rused[r] = true;
}

void SolveColumn(int c) {
    int r, var, count = 0;
    for (r = 0; r < rows; r++) {
        if (sols[vars[r][c]] == lmt) {
            var = vars[r][c];
            count++;
        } else {
            csums[c] -= sols[vars[r][c]];
        }
    }
    sols[var] = csums[c]/count;
    cused[c] = true;
}

string IntToString(int a) {
    string rtrn = "";
    rtrn += char(a/123);
    rtrn += char(a%123);
    return rtrn;
}

void Solve() {
    int r, c, i;
    while (cin >> rows >> cols) {
        Load();
        while (true) {
            r = FindRow();
            if (r+1) {
                SolveRow(r);
            } else {
                c = FindColumn();
                if (c+1) {
                    SolveColumn(c);
                } else {
                    break;
                }
            }
        }
        for (i = 0; i < solsmx; i++) {
            if (sols[i] != lmt) {
                cout << IntToString(i) << ' ' << sols[i] << '\n';
            }
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
