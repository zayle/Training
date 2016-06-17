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
    int a, b, c;
    cin >> a >> b >> c;
    if (c < b) swap(b, c);
    if (b < a) swap(a, b);
    if (c < b) swap(b, c);
    if ((pow(a, 2)+pow(b, 2)) == pow(c, 2)) {
        cout << c << ' ' << b << ' ' << a << '\n';
    } else {
        cout << "imposible" << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
