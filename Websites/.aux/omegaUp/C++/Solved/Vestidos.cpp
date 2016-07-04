#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, m, answer, i, a, b, auxA, auxB;
    cin >> n >> m;
    answer = -1;
    for (i = 1; i <= n; i++) {
        cin >> a >> b;
        if (b <= m) {
            if (answer == -1) {
                answer = i;
                auxA = a;
                auxB = b;
            } else {
                if (auxA < a) {
                    answer = i;
                    auxA = a;
                    auxB = b;
                } else if (auxA == a) {
                    if (b < auxB) {
                        answer = i;
                        auxA = a;
                        auxB = b;
                    }
                }
            }
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
