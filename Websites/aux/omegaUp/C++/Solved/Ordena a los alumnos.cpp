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

vector<int> scores;

void Solve() {
    int n, i, aux;
    bool spc;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> aux;
        scores.push_back(aux);
    }
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());
    spc = false;
    for (i = 0; i < n; i++) {
        if (spc) {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << scores[i];
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
