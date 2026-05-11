#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, long long>>> &adj, int a, int b, long long c) {
    adj[a].push_back({b, c});
}

void dijkstra(vector<vector<pair<int, long long>>> &adj, vector<vector<long long>> &dist, int n) {
    dist = vector<vector<long long>>(n + 1, vector<long long>(2, 1e18));
    dist[1][0] = 0;

    priority_queue<pair<long long, pair<int, int>>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second.first;
        int cupom_usado = pq.top().second.second;
        pq.pop();

        if (d > dist[u][cupom_usado]) continue;

        for (auto &aresta : adj[u]) {
            int v = aresta.first;     
            long long w = aresta.second;

            if (dist[u][cupom_usado] + w < dist[v][cupom_usado]) {
                dist[v][cupom_usado] = dist[u][cupom_usado] + w;
                pq.push({-dist[v][cupom_usado], {v, cupom_usado}});
            }

            if (cupom_usado == 0) {
                if (dist[u][0] + (w / 2) < dist[v][1]) {
                    dist[v][1] = dist[u][0] + (w / 2);
                    pq.push({-dist[v][1], {v, 1}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    vector<vector<long long>> dist;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);
    }

    dijkstra(adj, dist, n);

    cout << dist[n][1] << "\n";   
}