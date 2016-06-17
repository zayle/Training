#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 102;
bool grid[mx][mx];

void Recursion(int row, int col) {
    if (grid[row][col]) {
        grid[row][col] = false;
        Recursion(row-1, col-1);
        Recursion(row-1, col  );
        Recursion(row-1, col+1);
        Recursion(row  , col-1);
        Recursion(row  , col+1);
        Recursion(row+1, col+1);
        Recursion(row+1, col  );
        Recursion(row+1, col-1);
    }
}

void Solve() {
    int rows, cols, r, c, count;
    char aux;
    while (cin >> rows >> cols) {
        if (rows == 0) return;
        for (r = 1; r <= rows; r++) {
            for (c = 1; c <= cols; c++) {
                cin >> aux;
                grid[r][c] = (aux == '@');
            }
        }
        count = 0;
        for (r = 1; r <= rows; r++) {
            for (c = 1; c <= cols; c++) {
                if (grid[r][c]) {
                    count++;
                    Recursion(r, c);
                }
            }
        }
        cout << count << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
