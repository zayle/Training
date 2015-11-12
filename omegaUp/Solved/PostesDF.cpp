#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100000;
int posts[mx];

void Solve() {
    int k, n, i, answer;
    cin >> k >> n;
    for (i = 0; i < n; i++) {
        cin >> posts[i];
    }
    sort(posts, posts+n);
    answer = 1000000;
    for (i = k-1; i < n; i++) {
        answer = min(answer, (posts[i]-posts[(i-k)+1]));
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
