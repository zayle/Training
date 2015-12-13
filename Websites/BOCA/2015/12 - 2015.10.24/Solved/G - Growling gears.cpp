#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
typedef long double ld;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int t, i, n, j, answer;
    ld maxHeight, a, b, c, r, height;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        maxHeight = -1;
        for (j = 0; j < n; j++) {
            cin >> a >> b >> c;
            r = b/(2*a);
            height = -a*(pow(r, 2))+b*r+c;
            if ((maxHeight < height) || (maxHeight == -1)) {
                maxHeight = height;
                answer = j;
            }
        }
        cout << (answer+1) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
