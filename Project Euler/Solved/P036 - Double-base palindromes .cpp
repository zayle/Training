#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000000;

bool isPalindrome(string s) {
    int a = 0;
    int b = s.size()-1;
    while (a < b) {
        if (s[a] != s[b]) {
            return false;
        }
        a++;
        b--;
    }
    return true;
}

string GetBinary(int a) {
    string s;
    while (a > 0) {
        s += char((a%2)+48);
        a /= 2;
    }
    return s;
}

void Solve() {
    int i, sum = 0;
    for (i = 1; i < mx; i++) {
        if (isPalindrome(to_string(i))) {
            if (isPalindrome(GetBinary(i))) {
                sum += i;
            }
        }
    }
    cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
