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

const int mx = 10;
int digits[mx];

void Solve() {
    string s;
    int i, aux;
    while (getline(cin, s)) {
        for (i = 0; i < s.size(); i++) {
            aux = s[i]-'0';
            if ((0 <= aux) && (aux <= 9)) {
                digits[aux]++;
            }
        }
    }
    for (i = 0; i < mx; i++) {
        cout << "El "  << i << " aparece " << digits[i] << " veces." << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
