#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    long double n, k, t, aux;
    int i;
    cin >> n >> k >> t;
    aux = ((n*k*t)/100);
    for (i = 0; i < n; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << min(int(k), int(aux));
        aux -= k;
        if (aux < 1) {
            aux = 0;
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
