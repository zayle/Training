#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int MAX = 200001;
bool visited[MAX];
int maxd;
vector<int> graph[MAX];

int BFS(int a) {
    int aux, front, depth, i, j, last, sz;
    queue<int> q;
    fill(visited, (visited+MAX), false);
    q.push(a);
    depth = 0;
    while (!q.empty()) {
        maxd = max(maxd, depth);
        sz = q.size();
        for (i = 0; i < sz; i++) {
            front = q.front();
            q.pop();
            visited[front] = true;
            last = front;
            for (j = 0; j < graph[front].size(); j++) {
                aux = graph[front][j];
                if (!visited[aux]) q.push(aux);
            }
        }
        depth++;
    }
    return last;
}

void Solve() {
    int a, b, i, n;
    cin >> n;
    for (i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    BFS(BFS(1));
    cout << maxd << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
