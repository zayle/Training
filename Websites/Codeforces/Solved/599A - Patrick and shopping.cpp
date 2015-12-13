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

void Solve() {
    int a, b, c, answer;
    cin >> a >> b >> c;
    answer = a+b+c;
    answer = min(answer, (2*(a+b)));
    answer = min(answer, (2*(a+c)));
    answer = min(answer, (2*(b+c)));
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
