#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 20001;
int managers[mx];
bool used[mx];

int CountMembers(int a) {
    int count = 1;
    while (managers[a] != -1) {
        count++;
        a = managers[a];
    }
    return count;
}

void Solve() {
    int n, i, answer = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> managers[i];
    }
    for (i = 1; i <= n; i++) {
        if (!used[i]) {
            answer = max(answer, CountMembers(i));
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
