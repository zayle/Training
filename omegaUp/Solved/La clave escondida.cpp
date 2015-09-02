#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

 int GetSum(int n, string l) {
 	int i, aux, sum = 1;
 	vector<int> sums(n, 0);
 	for (i = 0; i < l.size(); i++) {
 		aux = ((int)l[i] - 64) % 32;
 		sums[i % n] += aux;
 	}
 	for (i = 0; i < n; i++) {
 		aux = (sums[i] % 10) + 1;
 		sum = (sum * aux) % 10;
 	}
 	return (sum + 1);
 }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	char aux;
	int n;
	string l;
	cin >> aux >> n >> l;
	cout << GetSum(n, l) << '-';
	cin >> aux >> n >> l;
	cout << (char)(GetSum(n, l) + 64) << '\n';
	return 0;
}