#include     <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 20000;
queue<int> q;
bool used[mx];

void Add(int a) {
    if (a < 0) return;
    if (mx-1 < a) return;
    if (!used[a]) q.push(a);
}

void Solve() {
    int m, n, depth, frnt, top, sz, i;
    cin >> m >> n;
    depth = -1;
    Add(m);
    while (!q.empty()) {
        depth++;
        sz = q.size();
        for (i = 0; i < sz; i++) {
            frnt = q.front();
            used[frnt] = true;
            if (frnt == n) break;
            q.pop();
            Add(frnt-1);
            Add(2*frnt);
        }
        if (frnt == n) break;
    }
    cout << depth << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
