#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000;

int GetCycleCount(int a){
	int count = 0;
	int num = 1, den = a;
	vector<int> pos(((10 * mx) + 1), 0);
	do {
		while (num < den) {
			num *= 10;
		}
		count++;
		num = num % den;
		if (pos[num] > 0) {
			return (count - pos[num]);
		} else {
			pos[num] = count;
		}
	} while (num > 0);
	return count;
}

void Solve() {
	int i, aux, maxCycle = 0, den;
	for (i = 983; i <= mx; i++) {
		aux = GetCycleCount(i);
		if (maxCycle < aux) {
			maxCycle = aux;
			den = i;
		}
	}
	cout << den << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}