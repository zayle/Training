#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100;
int num = 1, den = 1;

int GCD(int a, int b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        a = a % b;
        if (a < b) swap(a, b);
    }
    return a;
}

void Solve() {
    int i, j;
    double aux;
    int a, b, c, d;
    bool curious;
    for (i = 10; i < mx; i++) {
        for (j = 10; j < i; j++) {
            aux = (double(j)/i);
            a = j/10;
            b = j%10;
            c = i/10;
            d = i%10;
            curious = false;
            if (a == c) curious = (curious || ((double(b)/d) == aux));
            if (a == d) curious = (curious || ((double(b)/c) == aux));
            if (b == c) curious = (curious || ((double(a)/d) == aux));
            if ((b == d) && (b != 0)) curious = (curious || ((double(a)/c) == aux));
            if (curious) {
                num *= j;
                den *= i;
            }
        }
    }
    cout << (den/(GCD(num, den))) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
