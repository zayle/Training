#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int j, r, i, lmt, aux, winner;
    while (cin >> j >> r) {
        lmt = j*r;
        vector<int> points(j, 0);
        for (i = 0; i < lmt; i++) {
            cin >> aux;
            points[i%j] += aux;
        }
        aux = 0;
        for (i = 0; i < j; i++) {
            if (aux <= points[i]) {
                winner = i+1;
                aux = points[i];
            }
        }
        cout << winner << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
