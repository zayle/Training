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

const int mx = 100001;
int cnts[mx], pos[mx], as[mx];


void Solve() {
    int n, m, i, aux;
    string answer;
    bool spc;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> aux;
        cnts[aux]++;
        pos[aux] = i;
    }
    answer = "Possible";
    for (i = 1; i <= m; i++) {
        cin >> aux;
        if (cnts[aux] == 0) {
            answer = "Impossible";
        } else if (cnts[aux] == 1) {
            as[i] = pos[aux];
        } else {
            if (answer == "Possible") {
                answer = "Ambiguity";
            }
        }
    }
    cout << answer << '\n';
    if (answer == "Possible") {
        spc = false;
        for (i = 1; i <= m; i++) {
            if (spc) {
                cout << ' ';
            } else {
                spc = true;
            }
            cout << as[i];
        }
        cout << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
