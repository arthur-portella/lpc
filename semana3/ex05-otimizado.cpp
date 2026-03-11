#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    map<long long, vector<int>> mapa;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        mapa[a].push_back(i + 1);
    }

    for (int i = 0; i < q; i++) {
        long long x;
        int k;
        cin >> x >> k;

        auto it = mapa.find(x);

        if (it != mapa.end() && k <= it->second.size()) {
            cout << it->second[k - 1] << "\n";
        } else
            cout << "-1\n";
    }
}