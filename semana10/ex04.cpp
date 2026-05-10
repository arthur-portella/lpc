#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<tuple<int, int, int>> &adj, int a, int b, int c) {
    adj.push_back({a, b, c});
}

void bellmanFord(vector<tuple<int, int, int>> &adj, vector<int> &dist, int s, int n) {
    dist = vector<int>(n + 1, 1e9);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : adj) {
            if (dist[u] != 1e9 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> adj;
    vector<int> dist;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);
    }

    bellmanFord(adj, dist, 1, n);

    for (int i = 1; i < n + 1; i++) {
        if (dist[i] == 1e9)
            cout << "30000";
        else
            cout << dist[i];
        if (i != n)
            cout << " ";
        else
            cout << "\n";
    }
}