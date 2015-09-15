#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;
int maxPoints[mx];

void Solve() {
    int n, i, point, answer = 0;
    cin >> n >> maxPoints[0];
    answer = maxPoints[0];
    for (i = 1; i < n; i++) {
        cin >> point;
        maxPoints[i] = max(maxPoints[i-1]+point, point);
        if (answer < maxPoints[i-1]) {
            answer = maxPoints[i-1];
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
