#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Node {
    int to;
    int cost;
};

struct PQ {
    int node;
    int cost;
};

bool operator<(PQ a, PQ b) {
    return (a.cost > b.cost);
}

const int mx = 10001;
const int inf = -1;
vector<Node> graph[mx];
int costs[mx];
priority_queue<PQ> pq;

void Clear() {
    int i;
    for (i = 0; i < mx; i++) {
        graph[i].clear();
        costs[i] = inf;
    }
}

int Dijkstra(int c, int v) {
    int i, from, to, cost, node, j;
    PQ top;
    for (i = 0; i < v; i++) {
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    pq.push({1, 0});
    while (!pq.empty()) {
        top = pq.top();
        node = top.node;
        if (costs[node] == inf) {
            for (i = 0; i < graph[node].size(); i++) {
                to = graph[node][i].to;
                cost = graph[node][i].cost;
                for (j = 0; j < graph[to].size(); j++) {
                    pq.push({graph[to][j].to, graph[to][j].cost+cost+top.cost});
                }
            }
            costs[node] = top.cost;
        }
        pq.pop();
    }
    return costs[c];
}

void Solve() {
    int c, v;
    while (cin >> c >> v) {
        Clear();
        cout << Dijkstra(c, v) << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
