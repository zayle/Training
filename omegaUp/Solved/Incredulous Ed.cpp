#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

int const mx = 3;
int patterns[mx+1][mx+1];
int rows, cols;
vector<int> p;
string screen;
set<int> used;

void CreateP() {
    int r, c;
    p.clear();
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            p.push_back((mx*r+c)+1);
        }
    }
}

bool Move(int a, int b) {
    if (b < a) swap(a, b);
    screen[a] = 'x';
    screen[b] = 'x';
    if ((a == 1) && (b == 3) && (screen[2] == 'o')) return false;
    if ((a == 1) && (b == 7) && (screen[4] == 'o')) return false;
    if ((a == 1) && (b == 9) && (screen[5] == 'o')) return false;
    if ((a == 2) && (b == 8) && (screen[5] == 'o')) return false;
    if ((a == 3) && (b == 7) && (screen[5] == 'o')) return false;
    if ((a == 3) && (b == 9) && (screen[6] == 'o')) return false;
    if ((a == 4) && (b == 6) && (screen[5] == 'o')) return false;
    if ((a == 7) && (b == 9) && (screen[8] == 'o')) return false;
    return true;
}

void AddValids() {
    int i, val;
    screen = "oooooooooo";
    screen[p[0]] = 'x';
    val = p[0];
    used.insert(val);
    for (i = 1; i < p.size(); i++) {
        if (Move(p[i-1], p[i])) {
            val = 10*val+p[i];
            used.insert(val);
        } else {
            break;
        }
    }
}

void Solve() {
    int cs;
    cs = 0;
    while (cin >> rows >> cols) {
        if ((rows == 0) && (cols == 0)) return;
        cs++;
        if(cols < rows) swap(rows, cols);
        if (patterns[rows][cols] == 0) {
            CreateP();
            used.clear();
            do {
                AddValids();
            } while (next_permutation(p.begin(), p.end()));
            patterns[rows][cols] = used.size();
        }
        cout << "Case #" << cs << ": " << patterns[rows][cols] << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
