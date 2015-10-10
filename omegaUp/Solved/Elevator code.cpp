#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct PQ {
    int val;
    int sz;
};

bool operator<(PQ a, PQ b) {
    return (a.sz < b.sz);
}

priority_queue<PQ> neg;
priority_queue<PQ> pos;

string AddNext(string s) {
    int sz, aux;
    sz = 1;
    while (s[sz] == '#') sz++;
    aux = sz;
    if (s[0] != '#') sz--;
    if (s[0] == '-') {
        neg.push({0, sz});
    } else {
        pos.push({0, sz});
    }
    return s.substr(aux, s.size());
}

void Solve() {
    int t, i, j, sum;
    string s, digits;
    PQ top;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> s >> digits;
        s += 'x';
        while (s != "x") s = AddNext(s);
        sort(digits.begin(), digits.end());
        j = 0;
        sum = 0;
        while (!neg.empty()) {
            top = neg.top();
            neg.pop();
            top.val = 10*top.val+(digits[j]-'0');
            top.sz--;
            if (top.sz == 0) {
                sum -= top.val;
            } else {
                neg.push(top);
            }
            j++;
        }
        j = digits.size()-1;
        while (!pos.empty()) {
            top = pos.top();
            pos.pop();
            top.val = 10*top.val+(digits[j]-'0');
            top.sz--;
            if (top.sz == 0) {
                sum += top.val;
            } else {
                pos.push(top);
            }
            j--;
        }
        cout << sum << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
