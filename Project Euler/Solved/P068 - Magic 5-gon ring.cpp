#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 10;
int numbers[mx] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

long long GetAllAsInt() {
	int i;
	int aux[15] = {0, 1, 2, 3, 2, 4, 5, 4, 6, 7, 6, 8, 9, 8, 1};
	long long sum = 0;
	for (i = 0; i < 15; i++) {
		sum *= 10;
		if (numbers[aux[i]] > 9) sum *= 10;
		sum += numbers[aux[i]];
	}
	return sum;
}

bool Test1() {
	int a, b, c, d, e;
	a = numbers[0] + numbers[1] + numbers[2];
	b = numbers[3] + numbers[2] + numbers[4];
	c = numbers[5] + numbers[4] + numbers[6];
	d = numbers[7] + numbers[6] + numbers[8];
	e = numbers[9] + numbers[8] + numbers[1];
	return ((a == b) && (b == c) && (c == d) && (d == e));
}

bool Test2() {
	if (numbers[0] > numbers[3]) return false;
	if (numbers[0] > numbers[5]) return false;
	if (numbers[0] > numbers[7]) return false;
	if (numbers[0] > numbers[9]) return false;
	return true;
}

void Solve() {
	long long answer;
	do {
		if (Test1()) {
			if (Test2()) {
				answer = GetAllAsInt();
			}
		}
	} while (next_permutation(numbers, (numbers + mx)));
	cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}