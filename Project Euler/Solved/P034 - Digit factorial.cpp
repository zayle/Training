#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int Factorial(int a) {
	int i, factorial = 1;
	for (i = 2; i <= a; i++) {
		factorial *= i;
	}
	return factorial;
}

const int mx = Factorial(9) * 7;

int SumOfFactorials(int a) {
	int sum = 0;
	while (a > 0) {
		sum += Factorial(a % 10);
		a /= 10;
	}
	return sum;
}

void Solve() {
	int i, sum = 0;
	for (i = 10; i <= mx; i++) {
		if (i == SumOfFactorials(i)) {
			sum += i;
		}
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}