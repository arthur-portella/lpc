#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool primeiro_primo = true;

    for (int i = n + 1; i < m; i++) {
        bool primo = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                primo = false;
                break;
            }
        }
        
        if (primo)
            primeiro_primo = false;
    }

    for (int j = 2; j < m; j++) {
        if (m % j == 0) {
            primeiro_primo = false;
            break;
        }
    }

    if (primeiro_primo)
        cout << "YES\n";
    else
        cout << "NO\n";
}