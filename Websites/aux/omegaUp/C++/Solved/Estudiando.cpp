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

void Solve() {
    int a, b, aux;
    string answer;
    cin >> a >> b;
    answer = "\"Correcto\"";
    cin >> aux; if (aux != (a+b)) answer = "\"Incorrecto\"";
    cin >> aux; if (aux != (a-b)) answer = "\"Incorrecto\"";
    cin >> aux; if (aux != (a*b)) answer = "\"Incorrecto\"";
    cin >> aux; if (aux != (a/b)) answer = "\"Incorrecto\"";
    cin >> aux; if (aux != (a%b)) answer = "\"Incorrecto\"";
    cout << answer << '\n';
    if (answer == "\"Incorrecto\"") {
        cout << (a+b) << '\n';
        cout << (a-b) << '\n';
        cout << (a*b) << '\n';
        cout << (a/b) << '\n';
        cout << (a%b) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
