#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int i, j = 1, answer, open;
    string s;
    while (cin >> s) {
        if (s[0] == '-')  return;
        answer = 0;
        open = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    answer++;
                    open++;
                }
            }
        }
        answer += (open/2);
        cout << j << ". " << answer << '\n';
        j++;
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
