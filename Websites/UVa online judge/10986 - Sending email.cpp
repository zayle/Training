#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Node {
    int to;
    int lat;
};

struct PQ {
    int node;
    int lat;
};

bool operator<(PQ a, PQ b) {
    return (a.lat > b.lat);
}

const int mx = 20000;
const int inf = -1;
vector<Node> graph[mx];
int lats[mx];
priority_queue<PQ> pq;

void Clear() {
    int i;
    for (i = 0; i < mx; i++) {
        graph[i].clear();
        lats[i] = inf;
    }
}

int Dijkstra() {
    int n, m, s, t, i, from, to, lat, node;
    PQ top;
    Clear();
    cin >> n >> m >> s >> t;
    for (i = 0; i < m; i++) {
        cin >> from >> to >> lat;
        graph[from].push_back({to, lat});
        graph[to].push_back({from, lat});
    }
    pq.push({s, 0});
    while (!pq.empty()) {
        top = pq.top();
        node = top.node;
        if (lats[node] == inf) {
            for (i = 0; i < graph[node].size(); i++) {
                pq.push({graph[node][i].to, top.lat+graph[node][i].lat});
            }
            lats[node] = top.lat;
        }
        pq.pop();
    }
    return lats[t];
}

void Solve() {
    int n, i, aux;
    string answer;
    cin >> n;
    for (i = 1; i <= n; i++) {
        answer = "Case #";
        answer += to_string(i);
        answer += ": ";
        aux = Dijkstra();
        if (aux == inf) {
            answer += "unreachable";
        } else {
            answer += to_string(aux);
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
