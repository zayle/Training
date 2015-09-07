#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

int GetMinClicks(int number) {
	int size, i, clicks = 0;
	queue<int> q;
	vector<bool> used(1024, false);
	q.push(number);
	while (!q.empty()) {
		size = q.size();
		for (i = 0; i < size; i++) {
			number = q.front();
			if (!used[number]) {
				used[number] = true;
				if (number == 0) {
					return clicks;
				}
				q.push(number^11);
				q.push(number^23);
				q.push(number^38);
				q.push(number^89);
				q.push(number^186);
				q.push(number^308);
				q.push(number^200);
				q.push(number^464);
				q.push(number^416);
			}
			q.pop();
		}
		clicks++;
	}
	return clicks;
}

void Solve() {
	int i, j;
	int p, number;
	char aux;
	cin >> p;
	for (i = 0; i < p; i++) {
		number = 0;
		for (j = 0; j < 9; j++) {
			cin >> aux;
			if (aux == '*') {
				number += pow(2, j);
			}
		}
		cout << GetMinClicks(number) << '\n';
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