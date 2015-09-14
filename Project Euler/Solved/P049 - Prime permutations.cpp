#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 10000;
bool composites[mx];

void CreateSieve() {
	int i, j;
	for (i = 2; i < mx; i++) {
        if (!composites[i]) {
            for (j = i; j < mx; j += i) {
                composites[j] = true;
            }
            composites[i] = false;
        }
	}
}

void FindPrimePermutations(int a) {
    int i, j, delta, aux;
    string s = to_string(a);
    vector<int> permutations;
    do {
        if (!composites[stoi(s)])  {
            permutations.push_back(stoi(s));
        }
    } while(next_permutation(s.begin(), s.end()));
    for (i = 1; i < permutations.size(); i++) {
        delta = permutations[i] - permutations[0];
        for (j = i+1; j < permutations.size(); j++) {
            if ((permutations[j] - permutations[i]) == delta) {
                cout << a << ' ';
                cout << (a+delta) << ' ';
                cout << (a+delta+delta) << '\n';
            }
        }
    }
}

void Solve() {
    int i, j;
    for (i = 1000; i < mx; i++) {
        if (!composites[i]) {
            FindPrimePermutations(i);
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	CreateSieve();
	Solve();
	return 0;
}
