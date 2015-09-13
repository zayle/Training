#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 9;
string digits = "123456789";
vector<int> products;

void FindProducts() {
    int i, j;
    int a, b, c;
    for (i = 1; i < (mx-1); i++) {
        for (j = 1; (i+j) < mx; j++) {
            a = stoi(digits.substr(0, i));
            b = stoi(digits.substr(i, j));
            c = stoi(digits.substr((i+j), string::npos));
            if ((a*b) == c) {
                products.push_back(c);
            }
        }
    }
}

void Solve() {
    int i, sum = 0;
	do {
		FindProducts();
	} while(next_permutation(digits.begin(), digits.end()));
    sort(products.begin(), products.end());
	sum += products[0];
	for (i = 1; i < products.size(); i++) {
        if (products[i] != products[i-1]) {
            sum += products[i];
        }
    }
	cout << sum << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
