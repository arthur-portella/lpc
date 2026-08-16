#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<array<int, 26>> trie(1);
    vector<bool> fim(1, false);

    for (int i = 0; i < 26; i++)
        trie[0][i] = -1;

    while (k--) {
        string palavra;
        cin >> palavra;

        int atual = 0;

        for (char c : palavra) {
            int x = c - 'a';

            if (trie[atual][x] == -1) {

                trie[atual][x] = trie.size();

                array<int, 26> novo;
                for (int i = 0; i < 26; i++)
                    novo[i] = -1;

                trie.push_back(novo);
                fim.push_back(false);
            }

            atual = trie[atual][x];
        }

        fim[atual] = true;
    }

    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0)
            continue;

        int atual = 0;

        for (int j = i; j < n; j++) {
            int x = s[j] - 'a';

            if (trie[atual][x] == -1)
                break;

            atual = trie[atual][x];

            if (fim[atual]) {

                dp[j + 1] += dp[i];

                if (dp[j + 1] >= MOD)
                    dp[j + 1] -= MOD;
            }
        }
    }

    cout << dp[n] << '\n';
}