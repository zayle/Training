#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int p = 1001;
const int mx = p/2;
int solutions[p];

void Solve() {
    int a, b, sr, aux, i, count = 0, answer;
    double c;
    for (a = 1; a < mx; a++) {
        for (b = 1; b < mx; b++) {
            c = pow(a, 2) + pow(b, 2);
            sr = sqrt(c);
            if (pow(sr, 2) == c) {
                aux = a+b+sr;
                if (aux < p) {
                    solutions[aux]++;
                }
            }
        }
    }
    for (i = 1; i < p; i++) {
        if (count < solutions[i]) {
            answer = i;
            count = solutions[i];
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
