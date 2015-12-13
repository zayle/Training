#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    string n, sorted;
    int count = 0;
    cin >> n;
    while (n != "0") {
        count++;
        sorted = n;
        sort(sorted.begin(), sorted.end());
        n = to_string(stoi(n)-stoi(sorted));
    }
    cout << count << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
