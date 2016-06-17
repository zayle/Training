#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1001;
const int mod = 1000000;
long long count[mx];

void Solve() {
    int i, j, aux, n;
    count[0] = 1;
    count[1] = 1;
    for (i = 2; i < mx; i++) {
        for (j = 0; j < i; j++) {
            count[i] += ((count[j])*(count[(i-j)-1]));
            count[i] = count[i]%mod;
        }
    }
    cin >> n;
    cout << count[n] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
