#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Node {
    int to;
    int dist;
};

struct PQ {
    int node;
    int dist;
};

bool operator<(PQ a, PQ b) {
    return (a.dist > b.dist);
}

const int mx = 10001;
const int inf = -1;
vector<Node> graph[mx];
int dists[mx];
priority_queue<PQ> pq;

void Clear() {
    int i;
    for (i = 0; i < mx; i++) {
        graph[i].clear();
        dists[i] = inf;
    }
}

int Dijkstra() {
    int v, k, i, from, to, dist, a, b, node;
    PQ top;
    Clear();
    cin >> v >> k;
    for (i = 0; i < k; i++) {
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist});
    }
    cin >> a >> b;
    pq.push({a, 0});
    while (!pq.empty()) {
        top = pq.top();
        node = top.node;
        if (dists[node] == inf) {
            for (i = 0; i < graph[node].size(); i++) {
                pq.push({graph[node][i].to, top.dist+graph[node][i].dist});
            }
            dists[node] = top.dist;
        }
        pq.pop();
    }
    return dists[b];
}

void Solve () {
    int n, i, aux;
    string answer;
    cin >> n;
    for (i = 0; i < n; i++) {
        aux = Dijkstra();
        if (aux == inf) {
            answer = "NO";
        } else {
            answer = to_string(aux);
        }
        cout << answer << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
