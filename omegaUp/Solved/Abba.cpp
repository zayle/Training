#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 256;
int changes[mx];

void FillChanges() {
    int i;
    for (i = 0; i < mx; i++) {
        changes[i] = i;
    }
}

void Change(int a, int b) {
    int i;
    for (i = 0; i < mx; i++) {
        if (changes[i] == a) {
            changes[i] = b;
        }
    }
}

void Solve() {
    string s;
    int a, b, answer = 0;
    FillChanges();
    cin >> s;
    a = 0;
    b = s.size()-1;
    while (a < b) {
        if (changes[s[a]] != changes[s[b]]) {
            Change(changes[s[a]], changes[s[b]]);
            answer++;
        }
        a++;
        b--;
    }
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
