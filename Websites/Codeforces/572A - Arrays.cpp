#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100001;
int A[mx], B[mx];
int na, nb, k, m;

void Load() {
	int i;
	for (int i = 1; i <= na; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= nb; i++) {
		cin >> B[i];
	}
}

void Solve() {
	if (A[k] < B[nb - m + 1]) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> na >> nb >> k >> m;
	Load();
	Solve();
	return 0;
}