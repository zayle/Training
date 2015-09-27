#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100000;
string model = "123456789";

void Solve() {
    int i, j;
    string s, answer = "0";
    for (i = 1; i < mx; i++) {
        s = "";
        for (j = 1; s.size() < model.size(); j++) {
            s += to_string(i*j);
            if (s[0] < answer[0]) {
                break;
            }
        }
        if (s.size() == model.size()){
            if (is_permutation(s.begin(), s.end(), model.begin())) {
                if (stoi(answer) < stoi(s)) {
                    answer = s;
                }
            }
        }
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
