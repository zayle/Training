#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int GetPointCount(int a, int b) {
	long long points = 1;
	int exponent = 1, power;
	while ((power = pow(2, exponent++) - 1) <= b) {
		points += min(a, power) + 1;
	}
	points += max(0, ((a - (power - b)) + 1));
	return points;
}

void Solve() {
	int i;
	int n, a, b;
	cin >> n;
	for (i  = 0; i < n; i++) {
		cin >> a >> b;
		cout << GetPointCount(min(a, b), max(a, b)) <<  '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}