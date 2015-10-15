#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 2000001;
int powers[mx];

void Solve() {
    int n, i, power, answer;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> power;
        powers[power]++;
    }
    answer = 0;
    for (i = 0; i < mx-1; i++) {
        while (powers[i] > 1) {
            powers[i] -= 2;
            powers[i+1]++;
        }
        answer += powers[i];
    }
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
