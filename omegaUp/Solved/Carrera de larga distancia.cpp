#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int m, t, u, f, d, answer, i, aux;
    char c;
    cin >> m >> t >> u >> f >> d;
    answer = 0;
    for (i = 0; i < t; i++) {
        cin >> c;
        if (c == 'F') {
            aux = 2*f;
        } else {
            aux = u+d;
        }
        if ((m-aux) >= 0) {
            m -= aux;
            answer++;
        } else {
            m = -1;
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
