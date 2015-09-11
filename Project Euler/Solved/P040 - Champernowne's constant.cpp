#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;

void Solve() {
	int i, power = 1, count = 0, aux;
	int answer = 1;
	for (i = 1; power < mx; i++) {
		count += (log10(i) + 1);
		if (count >= power) {
			aux = pow(10, (count - power));
			aux = i / aux;
			aux = aux % 10;
			answer *= aux;
			power *= 10;
		}
	}
	cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}