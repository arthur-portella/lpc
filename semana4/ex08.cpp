#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, string>> resultado;
long long k;

void passo(long long f, string s) {
    
    if (k <= 0 || f <= 0)
        return;
    
    long long tam = s.length();

    if (f * tam <= k) {
        resultado.push_back({f, s});
        k -= f * tam;
    } else {
        long long rep_completas = k / tam;
        if (rep_completas > 0) {
            resultado.push_back({rep_completas, s});
            k -= rep_completas * tam;
        }
        if (k > 0) {
            resultado.push_back({1, s.substr(0, (int)k)});
            k = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m >> k;

    long long max_movimentos = 4 * n * m - 2 * n - 2 * m;

    if (k > max_movimentos) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (m > 1) 
            passo(m - 1, "RDU");
        if (m > 1)
            passo(m - 1, "L");
        passo(1, "D");
    }

    if (m > 1)
        passo(m - 1, "R");
    
    if (m > 1)
        passo(m - 1, "L");

    if (n > 1)
        passo(n - 1, "U");

    cout << "YES\n";
    cout << resultado.size() << "\n";
    for (const auto &r : resultado) {
        cout << r.first << " " << r.second << "\n";
    }

}