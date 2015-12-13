#include <fstream>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;
// fstream fs("in.txt", fstream::in);

ll GCD(ll a, ll b) {
    if (b < a) swap(a, b);
    while (a > 0) {
        b = b%a;
        if (b < a) swap(a, b);
    }
    return b;
}

ll LCM(ll a, ll b) {
    return ((a*b)/GCD(a, b));
}

void Solve() {
    ll v1, d1, v2, d2, cs, num, den, gcd;
    cs = 0;
    while (cin >> v1 >> d1 >> v2 >> d2) {
        if ((d1 == 0) && (v1 == 0) && (d2 == 0) && (v2 == 0)) return;
        cs++;
        cout << "Case #" << cs;
        if ((ld(d1)/v1) < (ld(d2)/v2)) {
            cout << ": You owe me a beer!" << '\n';
        } else {
            cout << ": No beer for the captain." << '\n';
        }
        den = LCM(v1, v2);
        num = (d1*(den/v1)+d2*(den/v2));
        den *= 2;
        gcd = GCD(num, den);
        cout << "Avg. arrival time: ";
        if ((num%den) == 0) {
            cout << (num/den) << '\n';
        } else {
            cout << (num/gcd) << '/' << (den/gcd) << '\n';
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
