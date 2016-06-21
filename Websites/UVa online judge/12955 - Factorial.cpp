#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 8;

int F(int a) {
    int f = 1;
    while (a > 0) {
        f *= a;
        a--;
    }
    return f;
}

void Solve() {
    int n, answer, i;
    while (cin >> n) {
        answer = 0;
        for (i = mx; i > 0; i--) {
            answer += (n/F(i));
            n -= (F(i)*int(n/F(i)));
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
