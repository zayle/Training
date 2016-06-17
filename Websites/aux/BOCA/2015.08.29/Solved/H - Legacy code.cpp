#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 400;
map<string, int> methods;
vector<int> roots;
bool table[mx][mx];
bool used[mx];
int n;

void AddMethod(string method) {
	if (methods.find(method) == methods.end()) {
		int aux = methods.size();
		methods[method] = aux;
		if (method.find("::PROGRAM::") != string::npos) {
			roots.push_back(methods[method]);
		}
	}
}

void LoadData() {
	int i, j, k;
	cin >> n;
	string method, caller;
	for (i = 0; i < n; ++i) {
		cin >> method >> k;
		method += "::";
		AddMethod(method);
		for (j = 0; j < k; j++) {
			cin >> caller;
			caller += "::";
			AddMethod(caller);
			table[methods[caller]][methods[method]] = true;
		}
	}
}

int Count(int a) {
	int i, count = 0;
	if (!used[a]) {
		used[a] = true;
		for (i = 0; i < n; i++) {
			if (table[a][i]) {
				count += Count(i);
			}
		}
		count++;
	}
	return count;
}

void Solve() {
	int i, aux = n;
	for (i = 0; i < roots.size(); i++) {
		if (!used[roots[i]]) {
			aux -= Count(roots[i]);
		}
	}
	cout << aux << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadData();
	Solve();
	return 0;
}