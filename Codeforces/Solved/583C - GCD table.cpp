#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 500;
const int mxmx = pow(mx, 2);
int table[mxmx];
bool used[mxmx];
vector<int> vals;
vector<int> aux;
int nn;

int GCD(int a, int b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        a %= b;
        if (a < b) swap(a, b);
    }
    return a;
}

void MarkUsed(int a) {
    int i, j = 0;
    aux.clear();
    for (i = 0; i < vals.size(); i++) {
        aux.push_back(GCD(a, vals[i]));
        aux.push_back(GCD(a, vals[i]));
    }
    sort(aux.begin(), aux.end());
    for (i = 0; (i < nn) && (j < aux.size()); i++) {
        if (table[i] == aux[j]) {
            if (!used[i]) {
                j++;
                used[i] = true;
            }
        }
    }
}

void Solve() {
    int n, i;
    cin >> n;
    nn = pow(n, 2);
    for (i = 0; i < nn; i++) {
        cin >> table[i];
    }
    sort(table, table+nn);
    for (i = nn-1; i > -1; i--) {
        if (!used[i]) {
            used[i] = true;
            MarkUsed(table[i]);
            vals.push_back(table[i]);
        }
    }
    cout << vals[0];
    for (i = 1; i < vals.size(); i++) {
        cout << ' ' << vals[i];
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
