#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<tuple<int, int, long long>> &adj, int a, int b, long long x) {
    adj.push_back({a, b, -x});
}

void bellmanFord(vector<tuple<int, int, long long>> &adj, vector<long long> &dist, int s, int n) {
    dist = vector<long long>(n + 1, 1e18);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : adj) {
            if (dist[u] != 1e18 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w] : adj) {
            if (dist[u] != 1e18 && dist[u] + w < dist[v]) {
                dist[v] = -1e18; 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, long long>> adj;
    vector<long long> dist;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        addEdge(adj, a, b, x);
    }

    bellmanFord(adj, dist, 1, n);

    if (dist[n] < -1e17)
        cout << "-1" << "\n";
    else
        cout << -dist[n] << "\n";
    
}