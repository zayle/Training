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
    int n, i, aux;
    double sum;
    cin >> n;
    sum = 0;
    for (i = 0; i < n; i++) {
        cin >> aux;
        sum += aux;
    }
    printf("%.2f\n", (sum/n));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
