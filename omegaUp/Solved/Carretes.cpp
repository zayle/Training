#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Solve() {
    int n, i, answer, aux;
    string a, b;
    cin >> n >> a >> b;
    answer = 0;
    for (i = 0; i < n; i++) {
        aux = abs((b[i]-'0')-(a[i]-'0'));
        answer += min(aux, (10-aux));
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
