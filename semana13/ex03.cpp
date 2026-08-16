#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    bool certo = true;

    while (t--) {
        certo = true;
        int a, b;
        cin >> a >> b;

        if ((a + b) % 3 != 0)
            certo = false;

        if (2*b < a || 2*a < b)
            certo = false;

        if (certo)
            cout << "YES\n";
        else 
            cout << "NO\n";

    }
}