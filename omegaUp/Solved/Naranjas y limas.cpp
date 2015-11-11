#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, oranges, limes, i, aux;
    cin >> n;
    oranges = 0;
    limes = 0;
    for (i = 0; i < n; i++) {
        cin >> aux;
        if (aux%2) {
            limes++;
        } else {
            oranges++;
        }
    }
    cout << oranges << ' ' << limes << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
