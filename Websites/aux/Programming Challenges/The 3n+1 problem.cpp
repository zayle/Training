#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 1000000;
int lengths[mx];

int GetNext(int a) {
	if ((a % 2) == 0) {
		return (a / 2);
	} else {
		return ((3 * a) + 1);
	}
}

void CreateLengths() {
	int i, aux, length;
	for (i = 1; i < mx; i++) {
		aux = i;
		length = 1;
		while (aux > 1) {
			if (aux < mx) {
				if (lengths[aux] > 0) {
					length += (lengths[aux] - 2);
					aux = 2;
				}
			}
			aux = GetNext(aux);
			length++;
		}
		lengths[i] = length;
	}
}

int GetMaxLength(int i, int j) {
	int maxLength = 0;
	for (i = i; i <= j; i++) {
		if (maxLength < lengths[i]) {
			maxLength = lengths[i];
		}
	}
	return maxLength;
}

void Solve() {
	int i, j;
	while (fs >> i >> j) {
		cout << min(i, j) << ' ' << max(i, j) << ' ' << GetMaxLength(min(i, j), max(i, j)) << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateLengths();
	Solve();
	return 0;
}