#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> vetor;

    long long aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        vetor.push_back({aux, i + 1});
    }

    int a = 0, b = vetor.size() - 1;

    sort(vetor.begin(), vetor.end());

    bool achou = false;
    while(a < b) {
        if (vetor[a].first + vetor[b].first < x)
            a++;
        else if (vetor[a].first + vetor[b].first > x)
            b--;
        else {
            cout << vetor[a].second << " " << vetor[b].second << "\n";
            achou = true;
            break;
        }
    }

    if (!achou)
        cout << "IMPOSSIBLE\n";
}