#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> atividade(n);
        for (int i = 0; i < n; i++) 
            cin >> atividade[i].first >> atividade[i].second;

        sort(atividade.begin(), atividade.end());

        int atividades = 1, inicio_ultima = atividade[0].first, fim_ultima = atividade[0].second;

        for (int i = 1; i < n; i++) {
            if (atividade[i-1].first == inicio_ultima && atividade[i].first == atividade[i-1].first && atividade[i].second < atividade[i-1].second) {
                fim_ultima = atividade[i].second;
            }

            if (fim_ultima <= atividade[i].first) {
                atividades++;
                inicio_ultima = atividade[i].first;
                fim_ultima = atividade[i].second;
            }
        }

        cout << atividades << "\n";
    }
}