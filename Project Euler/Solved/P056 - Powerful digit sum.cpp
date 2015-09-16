#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 101;
int digits[2*mx];

int GetDigitsSum(int a, int b) {
    int sz = 1, i, j, residue, sum = 0;
    digits[0] = 1;
    for (i = 0; i < b; i++) {
        residue = 0;
        for (j = 0; j < sz; j++) {
            digits[j] = (a*digits[j])+residue;
            residue = digits[j]/10;
            digits[j] = digits[j]%10;
        }
        while (residue > 0) {
            digits[j++] = residue%10;
            sz++;
            residue /= 10;
        }
    }
    for (i = 0; i < sz; i++) {
        sum += digits[i];
    }
    return sum;
}

void Solve() {
    int a, b, aux, answer = 0;
    for (a = 1; a < mx; a++) {
        for (b = 1; b < mx; b++) {
            aux = GetDigitsSum(a, b);
            if (answer < aux) {
                answer = aux;
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
