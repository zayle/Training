#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int p, n, i, candies, aux;
    cin >> p >> n;
    candies = 0;
    for (i = 0; i < n; i++) {
        cin >> aux;
        candies += aux;
    }
    cout << (candies/p) << ' ' << (candies%p) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
