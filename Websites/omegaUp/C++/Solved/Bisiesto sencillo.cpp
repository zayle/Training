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
    int year;
    char answer;
    cin >> year;
    answer = 'N';
    if ((year%4) == 0) {
        answer = 'S';
        if ((year%100) == 0) {
            answer = 'N';
            if ((year%400) == 0) {
                answer = 'S';
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
