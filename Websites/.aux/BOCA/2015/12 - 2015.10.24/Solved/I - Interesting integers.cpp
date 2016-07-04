#include <fstream>
#include <iostream>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 45;
int g1[mx];
int g2[mx];

void CreateGs() {
    int i;
    g1[1] = 1;
    g2[2] = 1;
    for (i = 3; i < mx; i++) {
        g1[i] = g1[i-1]+g1[i-2];
        g2[i] = g2[i-1]+g2[i-2];
    }
}

void SolveAux(int n) {
    ll i, j, aux;
    for (i = 1; true; i++) {
        for (j = 3; j < mx; j++) {
            aux = n-(g2[j]*i);
            if (0 < aux) {
                if ((aux%g1[j]) == 0) {
                    aux /= g1[j];
                    if (aux <= i) {
                        cout << aux << ' ' << i << '\n';
                        return;
                    }
                }
            } else {
                break;
            }
        }
    }
}

void Solve() {
    int t, i, n;
    CreateGs();
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        SolveAux(n);
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
