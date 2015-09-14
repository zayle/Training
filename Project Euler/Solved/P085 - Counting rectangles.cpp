#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mn = 2000000;
const int mx = 2001;

int CountRectangles(int rows, int cols) {
    int r, c, count = 0;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            count += ((rows-r)*(cols-c));
        }
    }
    return count;
}

void Solve() {
     int r, c, count;
     int minDelta = mn, row, col;
     for (r = 1; r < mx; r++) {
        for (c = 1; c < mx; c++) {
            count = CountRectangles(r, c);
            if (abs(mn-count) < minDelta) {
                minDelta = abs(mn-count);
                row = r;
                col = c;
            }
            if (count > mn) {
                break;
            }
        }
     }
     cout << (row*col) << ' ' ;
     cout << row << 'x' << col << ' ';
     cout << CountRectangles(row, col) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
