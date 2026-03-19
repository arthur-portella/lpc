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

        vector<int> x(n);
        for (int i = 0; i < n; i++){
            cin >> x[i];
        }

        int maior = 0, menor = 0x3f3f3f3f;
        for (int i = 0; i < n; i++){
            int infectados = 1;

            if (i != 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (x[j + 1] - x[j] <= 2) {
                        infectados++;
                    } else {
                        break;
                    }
                }
            }

            if (i != n-1) {
                for (int j = i + 1; j < n; j++) {
                    if (x[j] -  x[j - 1] <= 2) {
                        infectados++;
                    } else {
                        break;
                    }
                }
            }

            maior = max(infectados, maior);
            menor = min(infectados, menor);
        }

        cout << menor << " " << maior << "\n";
    }
}