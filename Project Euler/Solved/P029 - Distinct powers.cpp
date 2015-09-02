#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 100;
bool used[mx + 1];
vector<int> keys;

void CreateNames() {
	int i, j, k;
	for (i = 2; i <= mx; i++) {
		if (!used[i]) {
			j = 1;
			while (pow(i, j) <= mx) {
				used[int(pow(i, j))] = true;
				for (k = 2; k <= mx; k++) {
					keys.push_back(((j * k) * 1000) + i);
				}
				j++;
			}
		}
	}
}

void Solve() {
	int aux, i, count = 1;
	aux = keys[0];
	for (i = 1; i < keys.size(); i++) {
		if (aux != keys[i]) {
			count++;
		}
		aux = keys[i];
	}
	cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateNames();
	sort(keys.begin(), keys.end());
	Solve();
	return 0;
}