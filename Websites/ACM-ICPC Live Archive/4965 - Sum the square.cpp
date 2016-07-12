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

const int MAX = 730;
int used[MAX];
vector<pair<int, int>> depths;

int Sum(int a) {
    int sum;
    sum = 0;
    while (a) {
        sum += ((a%10)*(a%10));
        a /= 10;
    }
    return sum;
}

void AddDepths(int a, int b) {
    int depth;
    depth = 1;
    if (MAX <= a) {
        depths.push_back({a, depth++});
        a = Sum(a);
    }
    while (used[a] != b) {
        depths.push_back({a, depth++});
        used[a] = b;
        a = Sum(a);
    }
}

void Solve() {
    int a, answer, b, i;
    while (cin >> a >> b) {
        fill(used, (used+MAX), 0);
        depths.clear();
        if (!a && !b) return;
        AddDepths(a, 1);
        AddDepths(b, 2);
        sort(depths.begin(), depths.end());
        if (used[1] && used[4]) {
            answer = 0;
        } else {
            answer = (1<<16);
            for (i = 1; i < depths.size(); i++) {
                if (depths[i-1].first == depths[i].first) answer = min(answer, (depths[i-1].second+depths[i].second));
            }
        }
        cout << a << ' ' << b << ' ' << answer << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
