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

const int mx = 9;
const int sum = 15;
int a[mx];

void Solve() {
    int i;
    string answer;
    for (i = 0; i < mx; i++) {
        cin >> a[i];
    }
    answer = "SI";
    if ((a[0]+a[1]+a[2]) != sum) answer = "NO";
    if ((a[3]+a[4]+a[5]) != sum) answer = "NO";
    if ((a[6]+a[7]+a[8]) != sum) answer = "NO";
    if ((a[0]+a[3]+a[6]) != sum) answer = "NO";
    if ((a[1]+a[4]+a[7]) != sum) answer = "NO";
    if ((a[2]+a[5]+a[8]) != sum) answer = "NO";
    if ((a[0]+a[4]+a[8]) != sum) answer = "NO";
    if ((a[6]+a[4]+a[2]) != sum) answer = "NO";
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
