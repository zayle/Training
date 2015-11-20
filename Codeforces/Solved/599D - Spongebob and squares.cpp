#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

vector<pair<ll, ll>> sides;

void Solve() {
    ll x, sum, gauss, i, aux, cnt;
    cin >> x;
    sum = 0;
    gauss = 0;
    for (i = 1; sum < x; i++) {
        sum += pow(i, 2);
        gauss += i;
        aux = x-sum;
        if ((aux%gauss) == 0) {
            aux = i+(aux/gauss);
            sides.push_back({i, aux});
            sides.push_back({aux, i});
        }
    }
    sort(sides.begin(), sides.end());
    cnt = 1;
    for (i = 1; i < sides.size(); i++) {
        if (sides[i] != sides[i-1]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    cout << sides[0].first << ' ' << sides[0].second << '\n';
    for (i = 1; i < sides.size(); i++) {
        if (sides[i] != sides[i-1]) {
            cout << sides[i].first << ' ' << sides[i].second << '\n';
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
