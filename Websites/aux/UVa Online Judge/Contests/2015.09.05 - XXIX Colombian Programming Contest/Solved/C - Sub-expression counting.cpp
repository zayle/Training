#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);


string ConvertToRPN(string a) {
	int i = 0, operators = 0;
	string aux = "";
	for(i = 0; i< a.size(); i++) {
		if ((48 <= int(a[i])) && (int(a[i]) <=  57)) {
			if (i > 0) {
				if ((int(a[i-1]) < 48) || (57 < int(a[i-1]))) {
					aux += 'x';
				}
			} else {
				aux += 'x';
			}
		} else if ((97 <= int(a[i])) && (int(a[i]) <= 122)) {
			aux += 'x';
		} else if (a[i] == '+'
			    || a[i] == '-'
			    || a[i] == '*'
			    || a[i] == '/') {
			operators++;
		} else if (a[i] == ')') {
			aux += '+';
			operators--;
		}
	}
	while (operators-- > 0) {
		aux += '+';
	}
	return aux;
}

int Count(string a, string b) {
    int offset, count = 0;
    for (offset = a.find(b); offset != string::npos; offset = a.find(b, offset + b.length())) {
        ++count;
    }
    return count;
}

void Solve() {
	string a, b;
	while (cin >> a >> b) {
		a = ConvertToRPN(a);
		b = ConvertToRPN(b);
		cout << Count(b, a) << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}