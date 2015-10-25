#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, i, j, cnt;
    string s;
    char c;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        cnt = 0;
        for (j = 0; j < s.size(); j++) {
            c = s[j];
            if (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u') {
                cnt++;
            } else {
                cnt--;
            }
        }
        cout << s << '\n';
        cout << (0 < cnt) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
