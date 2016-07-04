#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
fstream fs("082 - Path sum; three ways.in.txt", fstream::in);

struct Coord {
	int row;
	int col;
	int sum;
};

bool operator<(Coord a, Coord b) {
	return (a.sum > b.sum);
}

const int mx = 80;
int numbers[mx][mx];
priority_queue<Coord> pq;

void LoadNumbers() {
	int i, j;
	for (i = 0; i < mx; i++) {
		for (j = 0; j < mx; j++) {
			fs >> numbers[i][j];
		}
	}
}

void AddCoord(int row, int col, int delta) {
	if ((0 <= row) && (row < mx)) {
		if ((0 <= col) && (col < mx)) {
			Coord c;
			c.row = row;
			c.col = col;
			c.sum = numbers[row][col] + delta;
			pq.push(c);
		}
	}
}

void Solve() {
	int i;
	Coord c;
	for (i = 0; i < mx; i++) {
		c.row = i;
		c.col = 0;
		c.sum = numbers[i][0];
		pq.push(c);
	}
	while (!pq.empty()) {
		c = pq.top();
		if (c.col == (mx - 1)) {
			cout << c.sum << '\n';
			return;
		}
		if (numbers[c.row][c.col] > -1) {
			numbers[c.row][c.col] = -1;
			AddCoord(c.row, (c.col + 1), c.sum);
			AddCoord((c.row - 1), c.col, c.sum);
			AddCoord((c.row + 1), c.col, c.sum);
		}
		pq.pop();
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadNumbers();
	Solve();
	return 0;
}
