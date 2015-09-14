#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 6;
string number;

void Solve() {
    int i, j;
    bool aux;
    string a, b;
    for (i = 1; true; i++) {
        aux = true;
        a = to_string(i);
        for (j = 2; j <= mx; j++) {
            b = to_string(i*j);
            if (a.size() == b.size()) {
                if (!is_permutation(a.begin(), a.end(), b.begin())) {
                    aux = false;
                    break;
                }
            } else {
                aux = false;
                break;
            }
        }
        if (aux) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
