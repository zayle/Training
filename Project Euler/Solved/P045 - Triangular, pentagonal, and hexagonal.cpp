#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    long long t = 2, tn = 3, p = 4, pn = 5, h = 5, hn = 6, count = 0;
    while (true) {
        hn += (h += 4);
        while (pn < hn) {
            pn += (p += 3);
        }
        while (tn < pn) {
            tn += (++t);
        }
        if ((tn == pn) && (pn == hn)) {
            if (++count == 2) {
                cout << tn << '\n';
                return;
            }
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
