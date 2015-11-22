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

const int mx = 100;
int numbers[mx];

void Solve() {
    int n, i;
    float answer;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers, (numbers+n));
    answer = numbers[n/2];
    if ((n%2) == 0) {
        answer += numbers[(n/2)-1];
        answer /= 2;
    }
    printf("%.1f\n", answer);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
