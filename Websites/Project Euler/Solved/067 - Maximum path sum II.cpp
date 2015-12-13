#include <fstream>
#include <iostream>
using namespace std;
fstream fs("067 - Maximum path sum II.in.txt", fstream::in);

const int mx = 100;
int triangle[mx + 1][mx];

void LoadTriangle() {
	int i, j;
	for (i = 1; i <= mx; i++) {
		for (j = 0; j < i; j++) {
			fs >> triangle[i][j];
		}
	}
}

void Solve() {
	int i, j, aux = 0;
	for (i = 2; i <= mx; i++) {
		triangle[i][0] += triangle[i - 1][0];
		for (j = 1; j < (i - 1); j++) {
			triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
		triangle[i][i - 1] += triangle[i - 1][i - 2];
	}
	for (i = 0; i < mx; i++) {
		aux = max(aux, triangle[mx][i]);
	}
	cout << aux << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadTriangle();
	Solve();
	return 0;
}
