#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, i, g, p, j, k, l;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> g >> p;
        cout << "Team #" << (i+1) << '\n';
        cout << "Games: " << g << '\n';
        cout << "Points: " << p << '\n';
        cout << "Possible records:"<< '\n';
        for (j = p/3; j > -1; j--) {
            for (k = p; k > -1; k--) {
                for (l = g; l > -1; l--) {
                    if ((j+k+l == g) && ((3*j)+k == p)) {
                        cout << j << '-' << k << '-' << l << '\n';
                    }
                }
            }
        }
        cout << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
