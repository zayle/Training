#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int j, d;

bool isWinner(int a, int b) {
    if (a > b) {
        if (a >= j) {
            if (a-b >= d) {
                return true;
            }
        }
    }
    return false;
}

void Solve() {
    int n, s, i, a = 0, b = 0, aSets = 0, bSets = 0;
    string record;
    cin >> n >> s >> j >> d >> record;
    for (i = 0; i < n; i++) {
        a += (record[i] == 'A');
        b += (record[i] == 'B');
        if (isWinner(a, b)) {
            aSets++;
            a = 0;
            b = 0;
        } else if (isWinner(b, a)) {
            bSets++;
            a = 0;
            b = 0;
        }
    }
    cout << aSets << ' ' << bSets << '\n';

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
