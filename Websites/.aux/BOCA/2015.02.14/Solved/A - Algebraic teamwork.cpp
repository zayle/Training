#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100001;
const int mod = 1000000007;
long long factorials[mx];

void CreateFactorials() {
	int i;
	factorials[0] = 1;
	for (i = 1; i < mx; i++) {
		factorials[i] = (factorials[i - 1] * i) % mod;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int t, n, aux;
	cin >> t;
	CreateFactorials();
	for (i = 0; i < t; i++) {
		cin >> n;
		aux = ((factorials[n] - 1) + mod) % mod;
		cout << aux << '\n';
	}
	return 0;
}