#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

vector<int> sequence;

void Solve() {
    int a, b, sz;
    cin >> a >> b;
    sequence.push_back(a);
    sequence.push_back(b);
    sz = 2;
    cout << a << ' ' << b;
    while (true) {
        sequence.push_back((sequence[sz-2]+sequence[sz-1])%10);
        sz++;
        cout << ' ' << sequence[sz-1];
        if ((sequence[sz-2] == a) && (sequence[sz-1] == b)) {
            break;
        }
    }
    cout << '\n' << (sz-2) << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
