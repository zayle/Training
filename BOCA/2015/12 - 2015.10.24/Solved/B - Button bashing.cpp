#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 3600;
vector<int> buttons;
vector<bool> useds;
vector<int> depths;
queue<int> q;

void Solve() {
    int cases, i, n, t, j, aux, frnt;
    cin >> cases;
    for (i = 0; i < cases; i++) {
        cin >> n >> t;
        buttons.clear();
        for (j = 0; j < n; j++) {
            cin >> aux;
            buttons.push_back(aux);
        }
        useds = vector<bool>(mx+1, false);
        depths = vector<int>(mx+1, 0);
        q.push(0);
        useds[0] = true;
        depths[0] = 0;
        while (!q.empty()) {
            frnt = q.front();
            useds[frnt] = true;
            for (j = 0; j < n; j++) {
                aux = frnt+buttons[j];
                if (aux < 0) aux = 0;
                if (mx < aux) aux = mx;
                if (!useds[aux]) {
                    q.push(aux);
                    useds[aux] = true;
                    depths[aux] = depths[frnt]+1;
                }
            }
            q.pop();
        }
        for (j = t; j <= mx; j++) {
            if (useds[j]) {
                break;
            }
        }
        cout << depths[j] << ' ' << (j-t) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
