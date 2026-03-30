#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> ap_desejado(n);
    for (int i = 0; i < n; i++) 
        cin >> ap_desejado[i];
    sort(ap_desejado.begin(), ap_desejado.end());

    vector<long long> tamanho_ap(m);
    for (int i = 0; i < m; i++) 
        cin >> tamanho_ap[i];
    sort(tamanho_ap.begin(), tamanho_ap.end());

    long long atendidos = 0;
    
    long long i = 0, j = 0;

    while(i < n && j < m) {
        if (ap_desejado[i] - k <= tamanho_ap[j] && tamanho_ap[j] <= ap_desejado[i] + k) {
            i++;
            j++;
            atendidos++;
        } else if (ap_desejado[i] > tamanho_ap[j]) {
            j++;
        } else if (ap_desejado[i] < tamanho_ap[j]) {
            i++;
        }
    }

    cout << atendidos << "\n";
}
