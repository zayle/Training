#include <fstream>
#include <iostream>
#include <map>
using namespace std;
// fstream fs("in.txt", fstream::in);

map<string, int> names;
bool friendships[1000][1000];

void LoadNames(int n) {
	int i;
	string name;
	for (i = 0; i < n; i++) {
		cin >> name;
		names[name] = i;
	}
}

void LoadFriendships(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> friendships[i][j];
		}
	}
}

void Solve() {
	int p, i;
	string a, b;
	cin >> p;
	for (i = 0; i < p; i++) {
		cin >> a >> b;
		cout << friendships[names[a]][names[b]] << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int n;
	cin >> n;
	LoadNames(n);
	LoadFriendships(n);
	Solve();
	return 0;
}