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
    if (n < 6) {
        cout << "No acredita" << '\n';
    } else if (n < 7) {
        cout << "Suficiente" << '\n';
    } else if (n < 8) {
        cout << "Regular" << '\n';
    } else if (n < 9) {
        cout << "Bien" << '\n';
    } else if (n < 10) {
        cout << "Muy bien" << '\n';
    } else {
        cout << "Excelente" << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
