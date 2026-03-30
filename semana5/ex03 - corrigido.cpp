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
            cin >> atividade[i].second >> atividade[i].first;

        sort(atividade.begin(), atividade.end());

        int atividades = 0, fim_ultima = -1;

        for (int i = 0; i < n; i++) {
            if (atividade[i].second >= fim_ultima) {
                atividades++;
                fim_ultima = atividade[i].first;
            }
        }

        cout << atividades << "\n";
    }
}