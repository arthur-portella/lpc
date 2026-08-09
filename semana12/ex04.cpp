#include <bits/stdc++.h>
using namespace std;

int parent[50001];
int rel[50001];

int find(int x) {

    if (parent[x] == x)
        return x;

    int p = parent[x];

    parent[x] = find(parent[x]);

    rel[x] = (rel[x] + rel[p]) % 3;

    return parent[x];
}

bool unite(int x, int y, int relacao) {

    int raizX = find(x);
    int raizY = find(y);

    if (raizX == raizY) {
        int diff = (rel[x] - rel[y] + 3) % 3;
        return diff == relacao;
    }

    parent[raizX] = raizY;

    rel[raizX] = (rel[y] - rel[x] + relacao + 3) % 3;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int falsas = 0;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rel[i] = 0;
        }

        for (int i = 0; i < k; i++) {
            int d, x, y;
            cin >> d >> x >> y;
            
            if(x > n || y > n) {
                falsas++;
                continue;
            }

            if (d == 2 && x == y) {
                falsas++;
                continue;
            }

            int relacao;

            if (d == 1)
                relacao = 0;
            else
                relacao = 1;

            if (!unite(x, y, relacao))
                falsas++; 
        }

        cout << falsas << "\n";
    }
}