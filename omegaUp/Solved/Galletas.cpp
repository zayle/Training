#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int dp[188][151][51];

int F(int g, int n1, int n5, int n10) {
    if (g == 0) {
        return 0;
    } else if (dp[g][n5][n10] > 0) {
        return dp[g][n5][n10];
    } else {
        int mn = 1200, aux;
        if (n10 > 0) {
            aux = F(g-1, n1+2, n5, n10-1)+1;
            mn = min(mn, aux);
            if (n1 > 2) {
                aux = F(g-1, n1-3, n5+1, n10-1)+4;
                mn = min(mn, aux);
            }
        }
        if (n5 > 0) {
            if (n1 > 2) {
                aux = F(g-1, n1-3, n5-1, n10)+4;
                mn = min(mn, aux);
            }
            if (n5 > 1) {
                aux = F(g-1, n1+2, n5-2, n10)+2;
                mn = min(mn, aux);
            }
        }
        if (n1 > 7) {
            aux = F(g-1, n1-8, n5, n10)+8;
            mn = min(mn, aux);
        }
        dp[g][n5][n10] = mn;
        return mn;
    }
}

void Solve() {
    int g, n1, n5, n10, answer = 0;
    int i, j, k;
    cin >> g >> n1 >> n5 >> n10;
    if ((n1+5*n5+10*n10) < (8*g)) {
        answer  = -1;
    } else {
        if (n10 >= g) {
            answer = g;
        } else {
            answer = F(g, n1, n5, n10);
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
