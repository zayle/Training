#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

char TransformChar(char a) {
    if (('0' <= a) && (a <= '9')) return 'x';
    if (('a' <= a) && (a <= 'z')) return 'x';
    if (a == '*') return '+';
    if (a == '/') return '+';
    if (a == '-') return '+';
    return a;
}

string TransformString(string a) {
    int i = 0, j;
    a[i] = TransformChar(a[i]);
    for (j = 1; j < a.size(); j++) {
        if (TransformChar(a[j]) == 'x') {
            if (a[i] != 'x') {
                i++;
                a[i] = 'x';
            }
        } else {
            i++;
            a[i] = TransformChar(a[j]);
        }
    }
    return a.substr(0, i+1);
}

void Solve() {
    int count, aux;
    string a, b;
    while (cin >> a >> b) {
        a = TransformString(a);
        b = TransformString(b);
        count = 0;
        aux = 0;
        if (a.size() <= b.size()) {
            while ((aux = b.find(a, aux)) != string::npos) {
                count++;
                aux += a.size();
            }
        }
        cout << count << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
