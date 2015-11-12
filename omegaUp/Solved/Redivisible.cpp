#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 2000001;
int pfactors[mx];
vector<int> pf;

void CreatePFactors() {
    int i, j;
    for (i = 2; i < mx; i++) {
        if (pfactors[i] == 0) {
            for (j = i; j < mx; j += i) {
                if (pfactors[j] == 0) {
                    pfactors[j] = i;
                }
            }
        }
    }
}

void Solve() {
    int l, h, answer, aux, cnt, i;
    CreatePFactors();
    cin >> l >> h;
    answer = 0;
    if (l == 1) {
        answer++;
        l++;
    }
    for (; l <= h; l++) {
        pf.clear();
        aux = l;
        while (aux != 1) {
            pf.push_back(pfactors[aux]);
            aux /= pfactors[aux];
        }
        cnt = 2;
        aux = 1;
        for (i = 1; i < pf.size(); i++) {
            if (pf[i] == pf[i-1]) {
                cnt++;
            } else {
                aux *= cnt;
                cnt = 2;
            }
        }
        aux *= cnt;
        if ((l%aux) == 0) {
            answer++;
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
