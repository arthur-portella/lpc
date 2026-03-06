#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int aux = 0;
        int operacoes = 0;

        while (aux < n) {
            if (aux + 1 < n && s[aux] == '(' && s[aux + 1] == ')') {
                operacoes++;
                aux += 2;
            } else if (aux + 1 < n && s[aux] == s[aux + 1]) {
                operacoes++;
                aux += 2;
            } else if (s[aux] == ')') {
                int j = aux + 1;
                while (j < n && s[j] != ')')
                    j++;

                if (j == n)
                    break;

                operacoes++;
                aux = j + 1;
            } else {
                break;
            }
        }

        cout << operacoes << " " << n - aux << "\n";
    }

}