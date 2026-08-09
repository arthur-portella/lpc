#include <bits/stdc++.h>
using namespace std;

int parent[200005];
int tamanho[200005];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        tamanho[a] += tamanho[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            tamanho[i] = 1;
        }
        
        for (int i = 0; i < n; i++) 
            unite(i, p[i]);
        
        for (int i = 0; i < n; i++)
            cout << tamanho[find(i)] << " ";

        cout << '\n';
    }
}