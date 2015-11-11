#include <algorithm>
#include <fstream>
#include <iostream>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100001;
ll open[mx], close[mx], numbers[mx], cnt[mx];

void Solve() {
    ll n, q, i, p1, p2, aux, sum;
    cin >> n >> q;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (i = 0; i < q; i++) {
        cin >> p1 >> p2;
        open[p1]++;
        close[p2]++;
    }
    aux = 0;
    for (i = 0; i < mx; i++) {
        aux += open[i];
        cnt[i] = aux;
        aux -= close[i];
    }
    sort(numbers, numbers+mx);
    sort(cnt, cnt+mx);
    sum = 0;
    for (i = 0; i < mx; i++) {
        sum += (numbers[i]*cnt[i]);
    }
    cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
