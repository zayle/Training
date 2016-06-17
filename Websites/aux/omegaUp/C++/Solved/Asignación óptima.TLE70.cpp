#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 22;
const int dpmx = pow(2, mx);
int powers[mx], n, cols[mx], dp[dpmx];
queue<int> pq;
bool used[dpmx];

void CreatePowers() {
    int i;
    powers[0] = 1;
    for (i = 1; i < mx; i++) {
        powers[i] = 2*powers[i-1];
    }
}

void LoadCols() {
    int i;
    for (i = 0; i < n; i++) {
        cin >> cols[i];
    }
}

void Solve() {
    int depth = 0, sz, i, top, j, aux;
    CreatePowers();
    cin >> n;
    pq.push(0);
    while (!pq.empty()) {
        if (depth < n) {
            LoadCols();
        }
        sz = pq.size();
        for (i = 0; i < sz; i++) {
            top = pq.front();
            for (j = 0; j < n; j++) {
                if (!(top&powers[j])) {
                    aux = top|powers[j];
                    dp[aux] = max(dp[aux], dp[top]+cols[j]);
                    if (!used[aux]) {
                        pq.push(aux);
                        used[aux] = true;
                    }
                }
            }
            pq.pop();
        }
        depth++;
    }
    cout << dp[int(pow(2, n))-1] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
