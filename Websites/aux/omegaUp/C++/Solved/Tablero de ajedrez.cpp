#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int row;
    char col;
    cin >> col >> row;
    if (((row+(col-'a'))%2) == 0) {
        cout << "BLANCO" << '\n';
    } else {
        cout << "NEGRO" << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
