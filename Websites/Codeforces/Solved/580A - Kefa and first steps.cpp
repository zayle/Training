#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, i, a, b, aux, mx;
    cin >> n;
    a = 0;
    aux = 0;
    mx = 0;
    for (i = 0; i < n; i++) {
        aux++;
        cin >> b;
        if (a > b) aux = 1;
        mx = max(mx, aux);
        a = b;
    }
    cout << mx << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
