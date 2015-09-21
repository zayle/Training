#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1001;
const long long mod = 10000000000;

void Solve() {
	int i, j;
	long long aux, answer = 0;
	for (i = 1; i < mx; i++) {
		aux = 1;
		for (j = 0; j < i; j++) {
			aux = (aux * i) % mod;
		}
		answer = (answer + aux) % mod;
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