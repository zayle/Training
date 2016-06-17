#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int a, b;
    while (cin >> a >> b) {
        cout << max(a, b) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
