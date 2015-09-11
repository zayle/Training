#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int const mx = 8;
int coins[mx] = {1, 2, 5, 10, 20, 50, 100, 200};

int F(int a, int b) {
	if (a < 0) {
		return 0;
	} else if ((a == 0) || (b == 0)) {
		return 1;
	} else {
		int i, coin;
		int count = 0;
		for (i = b; i > -1; i--) {
			coin = coins[i];
			count += F((a - coin), i);
		}
		return count;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cout << F(200, (mx - 1)) << '\n';
	return 0;
}