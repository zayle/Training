#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 10000001;
int end[mx];

int GetNext(int a) {
	int aux = 0;
	while (a > 0) {
		aux += pow((a % 10), 2);
		a /= 10;
	}
	return aux;
}

int GetEnd(int a) {
	int aux = a;
	while ((aux != 1) && (aux != 89)) {
		aux = GetNext(aux);
		if (aux < mx) {
			if (end[aux] > 0){
				aux = end[aux];
			}
		}
	}
	end[a] = aux;
	return aux;
}

void Solve() {
	int i, count = 0;
	for (i = 1; i < mx; i++) {
		if (GetEnd(i) == 89) {
			count++;
		}
	}
	cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}