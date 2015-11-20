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

const int mx = 10000;
int numbers[mx];

void Solve() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout << (is_sorted(numbers, (numbers+n)) ? "SI" : "NO") << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}