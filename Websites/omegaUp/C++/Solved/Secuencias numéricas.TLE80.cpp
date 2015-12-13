#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Pair {
	int pos;
	int val;
};

bool operator<(Pair a, Pair b) {
	return !(a.val < b.val);
}

int xs[1000000];
priority_queue<Pair> pq;

void LoadXs(int n) {
	int i;
	for (i = 0; i < n; i++) {
		cin >> xs[i];
	}
}

void Solve(int n) {
	int i;
	Pair top, aux;
	for (i = 0; i < n; i++) {
		while (!pq.empty()) {
			top = pq.top();
			if (top.val < xs[i]) {
				xs[top.pos] = i + 1;
				pq.pop();
			} else {
				break;
			}
		};
		aux.pos = i;
		aux.val = xs[i];
		pq.push(aux);
	}
	while (!pq.empty()) {
		top = pq.top();
		xs[top.pos] = -1;
		pq.pop();
	}
}

void ShowSolution(int n) {
	int i;
	cout << xs[0];
	for (i = 1; i < n; i++) {	
		cout << ' ' << xs[i];
	}
	cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int n;
	cin >> n;
	LoadXs(n);
	Solve(n);
	ShowSolution(n);
	return 0;
}