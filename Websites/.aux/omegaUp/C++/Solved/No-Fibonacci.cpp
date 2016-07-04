#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, a, b, i;
    bool spc;
    cin >> n;
    a = 1;
    b = 1;
    spc = false;
    for (i = 1; i < n; i++) {
        if (i < b) {
            if (spc) {
                cout << ' ';
            } else {
                spc = true;
            }
            cout << i;
        } else {
            a += b;
            swap(a, b);
        }
    }
    cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
