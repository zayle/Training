#include <cmath>
#include <fstream>
#include <iostream>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000001;
bool composites[mx];

void CreatePrimes() {
    int i, j;
    composites[0] = true;
    composites[1] = true;
    for (i = 2; i < mx; i++) {
        if (!composites[i]) {
            for (j = i; j < mx; j += i) {
                composites[j] = true;
            }
            composites[i] = false;
        }
    }
}

void Solve() {
    ll n, i, aux;
    string answer;
    CreatePrimes();
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> aux;
        answer = "NO";
        if (pow(int(sqrt(aux)), 2) == aux) {
            if (!composites[int(sqrt(aux))]) {
                answer = "YES";
            }
        }
        cout << answer << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
