#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, long long>>> &adj, int a, int b, long long w) {
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}

void dijkstra(vector<vector<pair<int, long long>>> &adj, vector<long long> &dist, int s, int n, vector<int> &pai) {
    dist = vector<long long>(n + 1, 1e18);
    pai = vector<int>(n + 1, -1);
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
                pai[v] = u;
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
        long long w;
        cin >> a >> b >> w;
        addEdge(adj, a, b, w);
    }

    vector<int> pai;

    dijkstra(adj, dist, 1, n, pai);

    if (dist[n] == 1e18)
        cout << "-1" << "\n";
    else {
        vector<int> caminho;
        for (int i = n; i != -1; i = pai[i]) 
            caminho.push_back(i);
        reverse(caminho.begin(), caminho.end());
        for (int i = 0; i < caminho.size(); i++) {
            cout << caminho[i];
            if (i != caminho.size() - 1)
                cout << " ";
            else 
                cout << "\n";
        }
    }     
}