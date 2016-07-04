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

const int MAX = 1000001;
bool used[MAX];
int ind[MAX], maxTails[MAX], targets[MAX];

void Solve() {
    int answer, count, e, front, i, j, maxTail, target;
    queue<int> q;
    cin >> e;
    for (i = 1; i <= e; i++) {
        cin >> target;
        targets[i] = target;
        ind[target]++;
    }
    for (i = 1; i <= e; i++) {
        if (!ind[i]) q.push(i);
    }
    while (!q.empty()) {
        front = q.front();
        q.pop();
        target = targets[front];
        maxTails[target] = max(maxTails[target], (maxTails[front]+1));
        ind[target]--;
        if (!ind[target]) q.push(target);
    }
    answer = 0;
    for (i = 1; i <= e; i++) {
        if (ind[i]) {
            count = 0;
            maxTail = 0;
            j = i;
            while (ind[j]) {
                count++;
                maxTail = max(maxTail, maxTails[j]);
                ind[j]--;
                j = targets[j];
            }
            answer = max(answer, (count+maxTail));
        }
    }
    cout << answer << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
