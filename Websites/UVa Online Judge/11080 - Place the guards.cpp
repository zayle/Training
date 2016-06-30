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

const int MAX = 200;
char colors[MAX];
vector<int> graph[MAX];

void Clear() {
    int i;
    fill(colors, (colors+MAX), 'W');
    for (i = 0; i < MAX; i++) graph[i].clear();
}

int BFS(int a) {
    char color;
    int blue, front, i, j, red, sz;
    queue<int> q;
    color = 'B';
    blue = 0;
    red = 0;
    q.push(a);
    while (!q.empty()) {
        sz = q.size();
        for (i = 0; i < sz; i++) {
            front = q.front();
            q.pop();
            if (colors[front] == 'W') {
                colors[front] = color;
                if (color == 'B') blue++;
                if (color == 'R') red++;
                for (j = 0; j < graph[front].size(); j++) q.push(graph[front][j]);
            } else {
                if (colors[front] != color) return -1;
            }
        }
        color = ((color == 'B') ? 'R' : 'B');
    }
    return max(1, min(blue, red));
}

void Solve() {
    int a, answer, b, bfs, e, i, j, n, t, v;
    cin >> t;
    for (i = 0; i < t; i++) {
        Clear();
        cin >> v >> e;
        for (j = 0; j < e; j++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        answer = 0;
        for (j = 0; j < v; j++) {
            if (colors[j] == 'W') {
                bfs = BFS(j);
                if (bfs == -1) {
                    answer = -1;
                    break;
                }
                answer += bfs;
            }
        }
        cout << answer << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    Solve();
    return 0;
}
