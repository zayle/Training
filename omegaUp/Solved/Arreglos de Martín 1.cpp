#include <fstream>
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Oper {
    ull l, r, d, cnt;
};

const int mx = 100001;
ull sequence[mx], ini[mx], fin[mx];
Oper opers[mx];

void Solve() {
    ull n, m, k, i, l, r, d, x, y, cnt;
    bool spc;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        cin >> sequence[i];
    }
    for (i = 1; i <= m; i++) {
        cin >> l >> r >> d;
        opers[i] = {l, r, d, 0};
    }
    for (i = 0; i < k; i++) {
        cin >> x >> y;
        ini[x]++;
        fin[y]++;
    }
    cnt = 0;
    for (i = 1; i <= m; i++) {
        cnt += ini[i];
        opers[i].cnt = cnt;
        cnt -= fin[i];
    }
    for (i = 1; i <= m; i++) {
        ini[i] = 0;
        fin[i] = 0;
    }
    for (i = 1; i <= m; i++) {
        ini[opers[i].l] += (opers[i].d*opers[i].cnt);
        fin[opers[i].r] += (opers[i].d*opers[i].cnt);
    }
    cnt = 0;
    spc = false;
    for (i = 1; i <= n; i++) {
        cnt += ini[i];
        if (spc) {
            cout << ' ';
        } else {
            spc = true;
        }
        cout << (sequence[i]+cnt);
        cnt -= fin[i];
    }
    cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
