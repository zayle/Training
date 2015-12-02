#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 3;
int numbers[mx];

void Solve() {
    string s;
    cin >> numbers[0] >> numbers[1] >> numbers[2] >> s;
    sort(numbers, (numbers+mx));
    cout << numbers[s[0]-'A'] << ' ';
    cout << numbers[s[1]-'A'] << ' ';
    cout << numbers[s[2]-'A'] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
