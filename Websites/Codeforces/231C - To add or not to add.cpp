#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int DELTA = 1000000000;
const int MAX = 100001;
ll numbers[MAX];

void Solve() {
    int i, j, k, maxocc, n, number, occ;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
        numbers[i] += DELTA;
    }
    sort(numbers, (numbers+MAX));
    reverse(numbers, (numbers+MAX));
    j = 0;
    occ = 0;
    maxocc = 0;
    for (i = 0; i < n; i++) {
        for (; j < n; j++) {
            if (k < (numbers[i]-numbers[j])) break;
            occ++;
            k -= (numbers[i]-numbers[j]);
        }
        if (maxocc <= occ) {
            maxocc = occ;
            number = numbers[i];
        }
        occ--;
        k += (((j-i)-1)*(numbers[i]-numbers[i+1]));
    }
    cout << maxocc << ' ' << (number-DELTA) << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
