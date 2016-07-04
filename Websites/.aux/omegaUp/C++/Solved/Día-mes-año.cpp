#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

string months[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

void Solve() {
    int n, i, m;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> m;
        if ((1 <= m) && (m <= 12)) {
            cout << months[m-1] << '\n';
        } else {
            cout << "Error" << '\n';
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
