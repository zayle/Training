#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, i, minCost, total, meat, cost;
    cin >> n;
    minCost = 101;
    total = 0;
    for (i = 0; i < n; i++) {
        cin >> meat >> cost;
        minCost = min(minCost, cost);
        total += (minCost*meat);
    }
    cout << total << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
