#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> mapa;

    int l;
    for (int i = 0; i < n; i++) {
        cin >> l;
        mapa[l]++;
    }

    int total = 0, maior = 0;
    for (const auto &i : mapa) {
        total++;
        maior = max(i.second, maior);
    }

    cout << maior << " " << total << "\n";
}