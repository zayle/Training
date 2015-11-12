#include <algorithm>
#include <fstream>
#include <iostream>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Coord {
    ll x, y;
};

bool operator<(Coord a, Coord b) {
    if (a.x < b.x) {
        return true;
    } else if (a.x == b.x) {
        return (a.y < b.y);
    } else {
        return false;
    }
}

const int mx = 100000;
Coord coords[mx];

void Solve() {
    ll n, k, i, x, y;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        coords[i] = {x, y};
    }
    sort(coords, (coords+n));
    for (i = 0; i < k; i++) {
        cin >> x >> y;
        cout << !binary_search(coords, (coords+n), Coord({x, y})) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
