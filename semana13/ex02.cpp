#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int letras[128];
    for (int i = 0; i < 128; i++)
        letras[i] = 0;

    for (char c : s1) {
        letras[c]++;
    }

    bool certo = true;

    for (char c : s2) {
        if (c != ' ') {
            if (letras[c]) {
                letras[c]--;
            } else {
                certo = false;
                break;
            }
        }
    }

    if (certo)
        cout << "YES\n";
    else
        cout << "NO\n";
}