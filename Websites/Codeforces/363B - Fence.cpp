#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 150000;
int heights[mx];

void Solve() {
    int n, k, i, sum = 0, mn, answer;
    cin >> n >> k;
    for (i = 0; i < k; i++) {
        cin >> heights[i];
        sum += heights[i];
    }
    mn = sum;
    answer = 1;
    for (i = k; i < n; i++) {
        cin >> heights[i];
        sum += heights[i];
        sum -= heights[i-k];
        if (sum < mn) {
            mn = sum;
            answer = (i-k)+2;
        }
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
