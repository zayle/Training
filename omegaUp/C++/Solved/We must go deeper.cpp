#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Pos {
    int r;
    int c;
};

const int mx = 9;
const int lmt = 3;
int board[mx][mx];
vector<Pos> pos;

void LoadBoard() {
    int r, c;
    Pos p;
    for (r = 0; r < mx; r++) {
        for (c = 0; c < mx; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) {
                p.r = r;
                p.c = c;
                pos.push_back(p);
            }
        }
    }
}

bool isValid(Pos p, int v) {
    int i, r, c, j;
    for (i = 0; i < mx; i++) {
        if (board[p.r][i] == v) return false;
        if (board[i][p.c] == v) return false;
    }
    r = p.r-(p.r%lmt);
    c = p.c-(p.c%lmt);
    for (i = 0; i < lmt; i++) {
        for (j = 0; j < lmt; j++) {
            if (board[r+i][c+j] == v) return false;
        }
    }
    return true;
}

void ShowBoard() {
    int r, c;
    for (r = 0; r < mx; r++) {
        for (c = 0; c < mx; c++) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
}

void R(int a) {
    if (a > -1) {
        Pos p = pos[a];
        for (int i = 1; i <= mx; i++) {
            if (isValid(p, i)) {
                board[p.r][p.c] = i;
                R(a-1);
            }
        }
        board[p.r][p.c] = 0;
    } else {
        ShowBoard();
        exit(0);
    }
}

void Solve() {
    LoadBoard();
    R(pos.size()-1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
    Solve();
	return 0;
}
