#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int moves[5];
int board[100][100];

void LoadMoves(int k) {
	int i, move;
	for (i = 0; i < k; i++) {
		cin >> move;
		moves[move]++;
	}
}

void LoadBoard(int rows, int cols) {
	int r, c;
	int offsetR = rows + ((moves[2] - moves[1]) % rows);
	int offsetC = cols + ((moves[4] - moves[3]) % cols);
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			cin >> board[(r + offsetR) % rows][(c + offsetC) % cols];
		}
	}
}

void ShowBoard(int rows, int cols) {
	int r, c;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int rows, cols, k;
	cin >> rows >> cols >> k;
	LoadMoves(k);
	LoadBoard(rows, cols);
	ShowBoard(rows, cols);
	return 0;
}