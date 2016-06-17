#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    string s;
    int answer;
    string::size_type pos;
    while (getline(cin, s)) {
        pos = 0;
        answer = 0;
        while ((pos = s.find("HREF", pos)) != string::npos) {
            answer++;
            pos += 4;
        }
        cout << answer << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
