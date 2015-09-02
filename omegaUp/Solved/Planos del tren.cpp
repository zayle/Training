#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Coord {
	int row;
	int col;
	int fuel;
};

bool operator<(Coord a, Coord b) {
	return (a.fuel > b.fuel);
}

int fuel, rows, cols;
char map[12][12];
priority_queue<Coord> coords;

void AddCoord(int r, int c, int f) {
	Coord coord;
	coord.row = r;
	coord.col = c;
	coord.fuel = f + 1;
	coords.push(coord);
}

void LoadMap() {
	int r, c;
	char aux;
	Coord coord;
	for (int r = 1; r <= rows; r++) {
		for (int c = 1; c <= cols; c++) {
			cin >> aux;
			map[r][c] = aux;
			if (aux == 'S') {
				AddCoord(r, c, -1);
			}
		}
	}
}

void Solve() {
	Coord coord;
	int r, c, f, total = 0;
	char aux;
	while (!coords.empty()) {
		coord = coords.top();
		r = coord.row;
		c = coord.col;
		f = coord.fuel;
		aux = map[r][c];
		if ((aux != 'x') && (f <= fuel)) {
			if ((aux == '|') ||
				(aux == '+') ||
				(aux == 'S')) {
				if ((map[r - 1][c] == '|') ||
					(map[r - 1][c] == '+')) {
					AddCoord((r - 1), c, f);
				}
				if ((map[r + 1][c] == '|') ||
					(map[r + 1][c] == '+')) {
					AddCoord((r + 1), c, f);
				}

			}
			if ((aux == '-') ||
				(aux == '+') ||
				(aux == 'S')) {
				if ((map[r][c - 1] == '-') ||
					(map[r][c - 1] == '+')) {
					AddCoord(r, (c - 1), f);
				}
				if ((map[r][c + 1] == '-') ||
					(map[r][c + 1] == '+')) {
					AddCoord(r, (c + 1), f);
				}
			}
			total++;
			map[r][c] = 'x';
		}
		coords.pop();
	}
	cout << total << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> fuel >> rows >> cols;
	LoadMap();
	Solve();
	return 0;
}