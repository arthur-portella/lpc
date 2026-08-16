#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string t = "^";

    for (char c : s) {
        t += "#";
        t += c;
    }

    t += "#$";

    int n = t.size();

    vector<int> p(n, 0);

    int centro = 0;
    int direita = 0;

    int melhor = 0;
    int posMelhor = 0;

    for (int i = 1; i < n - 1; i++) {

        int espelho = 2 * centro - i;

        if (i < direita)
            p[i] = min(direita - i, p[espelho]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > direita) {
            centro = i;
            direita = i + p[i];
        }

        if (p[i] > melhor) {
            melhor = p[i];
            posMelhor = i;
        }
    }

    int inicio = (posMelhor - melhor) / 2;

    cout << s.substr(inicio, melhor) << '\n';
}