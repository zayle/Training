#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

long long Sum(long long a) {
    if (a == 0) {
        return 0;
    } else {
        long long sum = 0, lg, power;
        lg = log2(a);
        power = pow(2, lg);
        sum += (lg*power)/2;
        sum += ((a-power)+Sum(a-power));
        return sum;
    }
}

void Solve() {
    long long n;
    cin >> n;
    n /= 2;
    cout << Sum(n+1) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
