#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100001;
int n, parent;
vector<int> children[mx];
queue<int> cola;

void Load() {
	int i, aux;
	for (int i = 0; i <= n; i++) {
		cin >> aux;
		if (aux == i) {
			parent = i;
		} else {
			children[aux].push_back(i);
		}
	}
}

void Solve() {
	int total, size, i, front, j;
	bool stop = false;
	cola.push(parent);
	while (!cola.empty() && !stop) {
		total = 0;
		size = cola.size();
		for (i = 0; i < size; i++) {
			front = cola.front();
			for (j = 0; j < children[front].size(); j++) {
				cola.push(children[front][j]);
			}
			if (front == 0) {
				stop = true;
			} else {
				total++;
			}
			cola.pop();
		}
	}
	cout << total << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> n;
	Load();
	Solve();
	return 0;
}