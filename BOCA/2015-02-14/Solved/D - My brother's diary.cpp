#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

string entry;

void Solve() {
	int i, aux, mx = 0, distance;
	vector<int> letters(26, 0);
	for (i = 0; i < entry.size(); i++) {
		aux = int(entry[i] - 65);
		if ((0 <= aux) && (aux <= 26)) {
			letters[aux]++;
		}
	}
	for (i = 0; i < 26; i++) {
		if (mx < letters[i]) {
			mx = letters[i];
		}
	}
	aux = 0;
	for (i = 0; i < 26; i++) {
		if (letters[i] == mx) {
			aux++;
			distance = ((i - 4) + 26) % 26;
		}
	}
	if (aux == 1) {
		cout << distance << ' ';
		for (i = 0; i < entry.size(); i++) {
			aux = int(entry[i]) - 65;
			if ((0 <= aux) && (aux <= 26)) {
				aux = 65 + (((aux - distance) + 26) % 26);
				cout << char(aux);
			} else {
				cout << entry[i];
			}
		}
		cout << '\n';
	} else {
		cout << "NOT POSSIBLE" << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int c;
	cin >> c;
	getline(cin, entry);
	for (int i = 0; i < c; i++) {
		getline(cin, entry);
		Solve();
	}
	return 0;
}