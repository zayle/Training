#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fs("022 Names scores.in.txt", fstream::in);

vector<string> names;

void LoadNames() {
	string name;
	while (fs >> name) {
		names.push_back(name);
	}
}

int GetNameValue(string name) {
	int i, value = 0;
	for (i = 0; i < name.size(); i++) {
		value += (int(name[i]) - 64);
	}
	return value;
}

void Solve() {
	int i, sum = 0;
	for (int i = 0; i < names.size(); i++) {
		sum += ((i + 1) * GetNameValue(names[i]));
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadNames();
	sort(names.begin(), names.end());
	Solve();
	return 0;
}
