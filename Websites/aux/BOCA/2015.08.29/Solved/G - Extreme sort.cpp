#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
	int n, i, a, b;
	string answer = "yes";
	cin >> n >> a;
	for (int i = 1; i < n; i++) {
		cin >> b;
		if (!(a <= b)) {
			answer = "no";
		}
		a = b;
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