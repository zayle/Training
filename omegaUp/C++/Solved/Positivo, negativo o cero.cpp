#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "NEGATIVO" << '\n';
    } else if (n == 0) {
        cout << "CERO" << '\n';
    } else {
        cout << "POSITIVO" << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
