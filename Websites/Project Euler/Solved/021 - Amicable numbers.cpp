#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 10001;
int sums[mx];

void CreateSums() {
	int i, j, aux, sum;
	for (i = 1; i < mx; i++) {
		aux = sqrt(i);
		sum = 1;
		for (j = 2; j <= aux; j++) {
			if ((i % j) == 0) {
				sum += j;
				if (j != (i / j)) {
					sum += i / j;
				}
			}
		}
		sums[i] = sum;
	}
}

void Solve() {
	int i, sum = 0;
	for (i = 1; i < mx; i++) {
		if (i != sums[i]) {
			if (i == sums[sums[i]]) {
				sum += i;
			} 
		}
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateSums();
	Solve();
	return 0;
}