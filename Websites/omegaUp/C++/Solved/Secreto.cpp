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

const int mx = 1000;
int numbers[mx][mx], n;
char password000[mx][mx];
char password090[mx][mx];
char password180[mx][mx];
char password270[mx][mx];

void ShowNumbers(char password[mx][mx]) {
    int r, c;
    bool spc;
    spc = false;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (password[r][c] == 'X') {
                if (spc) {
                    cout << ' ';
                } else {
                    spc = true;
                }
                cout << numbers[r][c];
            }
        }
    }
    cout << '\n';
}

void Solve() {
    int r, c, m;
    char aux;
    cin >> n;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            cin >> numbers[r][c];
        }
    }
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            cin >> aux;
            password000[r][c] = aux;
            password090[c][(n-r)-1] = aux;
            password180[(n-r)-1][(n-c)-1] = aux;
            password270[(n-c)-1][r] = aux;
        }
    }
    cin >> m;
    if ((m%4) == 0) {
        ShowNumbers(password000);
    } else if ((m%4) == 1) {
        ShowNumbers(password090);
    } else if ((m%4) == 2) {
        ShowNumbers(password180);
    } else {
        ShowNumbers(password270);
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
