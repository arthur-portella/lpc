#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, long long>>> &adj, int a, int b, long long c) {
    adj[a].push_back({b, c});
}

void dijkstra(vector<vector<pair<int, long long>>> &adj, vector<long long> &dist, int s, int n) {
    dist = vector<long long>(n + 1, 1e18);
    dist[s] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &aresta : adj[u]) {
            int v = aresta.first;     
            long long w = aresta.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
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
    vector<long long> dist;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);
    }

    dijkstra(adj, dist, 1, n);

    for (int i = 1; i < n + 1; i++) {
        cout << dist[i];
        if (i != n)
            cout << " ";
        else 
            cout << "\n";
    }
        
}