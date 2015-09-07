#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 8;
bool board[mx][mx];

void Mark(int r, int c) {
	int i;
	for (i = 0; i < mx; i++) {
		board[r][i] = true;
		board[i][c] = true;
		if (((r-i) > -1) && ((c-i) > -1)) board[r-i][c-i] = true;
		if (((r-i) > -1) && ((c+i) < mx)) board[r-i][c+i] = true;
		if (((r+i) < mx) && ((c-i) > -1)) board[r+i][c-i] = true;
		if (((r+i) < mx) && ((c+i) < mx)) board[r+i][c+i] = true;
	}
}

void Solve() {
	int r, c, queens = 0;
	char aux;
	string answer = "valid";
	for (r = 0; r < mx; r++) {
		for (c = 0; c < mx; c++) {
			cin >> aux;
			if (aux == '*') {
				queens++;
				if (board[r][c]) {
					answer = "invalid";
				} else {
					Mark(r, c);
				}
			}
		}
	}
	if (queens != 8) {
		answer = "invalid";
	}
	cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}