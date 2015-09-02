#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

bool isPalindrome(int a) {
	int aux = a, b = 0;
	while (aux > 0) {
		b *= 10;
		b += (aux % 10);
		aux /= 10;
	}
	return (a == b);
}

void Solve() {
	int i, j, aux, mx = 0;
	for (int i = 100; i < 1000; i++) {
		for (j = 100; j < 1000; j++) {
			aux = i * j;
			if (isPalindrome(aux)) {
				if (mx < aux) {
					mx = aux;
				}
			}
		}
	}
	cout << mx << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}