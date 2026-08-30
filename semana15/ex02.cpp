#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int resposta = (s[0] - 'a') * 25;

        if (s[1] < s[0])
            resposta += s[1] - 'a' + 1;
        else
            resposta += s[1] - 'a';

        cout << resposta << '\n';
    }
}