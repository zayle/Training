#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("042 - Coded triangle numbers.in.txt", fstream::in);

bool isTriangle(int a) {
	int sr = sqrt(2 * a);
	return (((sr * (sr + 1)) / 2) == a);
}

void Solve() {
	int i, aux, count = 0;
	string name;
	while (fs >> name) {
		aux = 0;
		for (i = 0; i < name.size(); i++) {
			aux += (int(name[i]) - 64);
		}
		if (isTriangle(aux)) {
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
