#include <fstream>
#include <iostream>
#include <stack>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Pair {
	int pos;
	int val;
};

const int mx = 1000000;
int js[mx];
stack<Pair> pairs;

void Solve(int n) {
	int i;
	Pair pair, aux;
	for (i = 0; i < n; i++) {
		cin >> pair.val;
		while (!pairs.empty()) {
			aux = pairs.top();
			if (aux.val < pair.val) {
				js[aux.pos] = i + 1;
				pairs.pop();
			} else {
				break;
			}
		} 
		pair.pos = i;
		pairs.push(pair);
	}
	while (!pairs.empty()) {
		aux = pairs.top();
		js[aux.pos] = -1;
		pairs.pop();
	} 
}

void ShowSolution(int n) {
	int i;
	cout << js[0];
	for (i = 1; i < n; i++) {
		cout << ' ' << js[i];
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int n;
	cin >> n;
	Solve(n);
	ShowSolution(n);
	return 0;
}