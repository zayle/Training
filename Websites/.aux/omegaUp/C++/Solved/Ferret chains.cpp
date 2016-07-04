#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

vector<int> used;

bool IsUsed(int a) {
    for (int i = 0; i < used.size(); i++) {
        if (used[i] == a) {
            return true;
        }
    }
    return false;
}

void Solve() {
    string n, a, b;
    int cnt;
    cin >> n;
    while (n != "0") {
        used.clear();
        cnt = 0;
        while (!IsUsed(stoi(n))) {
            cnt++;
            used.push_back(stoi(n));
            sort(n.begin(), n.end());
            a = n;
            reverse(n.begin(), n.end());
            b = n;
            n = to_string(stoi(b)-stoi(a));
        }
        cout << "Chain length " << cnt << '\n';
        cin >> n;
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
