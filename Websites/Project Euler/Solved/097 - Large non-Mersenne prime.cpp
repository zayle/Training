#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 7830457;
const long long mod = 10000000000;

void Solve() {
	int i;
	long long answer = 28433;
	for (i = 0; i < mx; i++) {
		answer = (2 * answer) % mod;
	}
	cout << ((answer + 1) % mod) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}