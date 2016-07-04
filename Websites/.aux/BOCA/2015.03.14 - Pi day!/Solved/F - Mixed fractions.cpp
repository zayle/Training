#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
	int a, b, aux;
	while (cin >> a >> b) {
		if ((a != 0) && (b != 0)) {
			aux = a / b;
			cout << aux << ' ' << (a - (b * aux)) << " / " << b << '\n';
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}