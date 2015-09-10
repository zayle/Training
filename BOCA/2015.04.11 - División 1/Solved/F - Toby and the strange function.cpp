#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
	int i, j, t;
	long long n;
	string s;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n >> s;
		n = n % s.size();
		for (j = (s.size() - n); j < s.size(); j++) {
			cout << s[j];
		}
		for (j = 0; j < (s.size() - n); j++) {
			cout << s[j];
		}
		cout << '\n';
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
