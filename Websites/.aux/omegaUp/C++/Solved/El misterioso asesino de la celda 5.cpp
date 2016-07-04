#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 101;
bool mp[mx][mx];

void Solve() {
    int rows, cols, n, i, r, c, answer;
    cin >> rows >> cols >> n;
    for (i = 0; i < n; i++) {
        cin >> r >> c;
        mp[r][c] = true;
    }
    answer = 0;
    for (r = 2; r <= rows; r++) {
        for (c = 2; c <= cols; c++) {
            answer += (!mp[r-1][c-1] && !mp[r-1][c] && !mp[r][c-1] && !mp[r][c]);
        }
    }
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
