#include <cmath>
#include <fstream>
#include <iostream>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

ll Gauss(ll a) {
    ll gauss;
    gauss = 0;
    while (a > 0) {
        gauss += a;
        a--;
    }
    return gauss;
}

ll GetSum(ll a, ll exp) {
    ll sum, power, cnt;
    power = pow(10, exp);
    if (exp == 0) return Gauss(a);
    if (a < power) return GetSum(a, exp-1);
    sum = 0;
    cnt = 0;
    while (power <= a) {
        sum += (power*cnt);
        sum += (((power/10)*Gauss(9))*exp);
        cnt++;
        a -= power;
    }
    sum += (cnt*(a+1));
    return (sum+GetSum(a, exp-1));
}

void Solve() {
    ll cases, i, a, b;
    cin >> cases;
    for (i = 0; i < cases; i++) {
        cin >> a >> b;
        cout << (GetSum(b, 15)-GetSum(a-1, 15)) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
