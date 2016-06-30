#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#include<vector>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int MaxLevel(string s) {
    int i, level, maxLevel;
    level = 0;
    maxLevel = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '(') level++;
        maxLevel = max(maxLevel, level);
        if (s[i] == ')') level--;
    }
    return maxLevel;
}

void Solve() {
    int i, j, maxLevel, t;
    string answer, s;
    t = 1;
    while (cin >> s) {
        if (s == "()") return;
        maxLevel = MaxLevel(s);
        j = -1;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                maxLevel++;
                s[++j] = s[i];
            } else {
                if (s[i] == ')') {
                    while (s[j-1] != '(') {
                        if (maxLevel%2) {
                            s[j-1] = (((s[j-1] == 'T') || (s[j] == 'T')) ? 'T' : 'F');
                        } else {
                            s[j-1] = (((s[j-1] == 'T') && (s[j] == 'T')) ? 'T' : 'F');
                        }
                        j--;
                    }
                    s[j-1] = s[j];
                    j--;
                    maxLevel--;
                } else {
                    s[++j] = s[i];
                }
            }
        }
        answer = ((s[0] == 'T') ? ". true\n" : ". false\n");
        cout << (t++) << answer;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
