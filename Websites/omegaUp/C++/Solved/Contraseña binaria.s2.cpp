#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
// fstream fs("in.txt", fstream::in);

long long Sum(long long a) {
	long long sum = 0;
	while (a) {
		int exponent = log2(a);
		sum += (a - pow(2, exponent)) + 1;
		sum += (exponent * pow(2, exponent - 1));
		a -= pow(2, exponent);
	}
	return sum;
}

void Solve() {
	long long n;
	cin >> n;
	n /= 2;
	cout << Sum(n) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
