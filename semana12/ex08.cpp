#include <bits/stdc++.h>
using namespace std;

int parent[1001];

int find (int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite (int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = parent[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
            parent[i] = i;
    }

    vector<pair<int, int>> extra;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b))
            extra.push_back({a,b});
        else
            unite(a, b);
    }

    vector<int> representantes;

    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            representantes.push_back(i);

    cout << representantes.size() - 1 << '\n';

    for (int i = 0; i < representantes.size() - 1; i++) {
        int a = extra[i].first;
        int b = extra[i].second;

        int u = representantes[i];
        int v = representantes[i + 1];

        cout << a << " " << b << " " << u << " " << v << '\n';
    }
}