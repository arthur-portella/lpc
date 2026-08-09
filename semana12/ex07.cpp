#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;

        set<pair<int,int>> blocos[26];
        int inicio = 0, n = s.size();

        while (inicio < n) {
            int fim = inicio;

            while (fim + 1 < n && s[fim + 1] == s[inicio])
                fim++;

            blocos[s[inicio] - 'A'].insert({inicio, fim});
            inicio = fim + 1;
        }

        int q;
        cin >> q;

        cout << "Case " << i << ":\n";

        while (q--) {

            int tipo, pos;
            cin >> tipo >> pos;

            char c = s[pos];

            if (tipo == 1) {
                auto &st = blocos[c - 'A'];
                auto it = st.upper_bound({pos, INT_MAX});
                --it;
                cout << it->second - it->first + 1 << '\n';
            } else {
                auto &st = blocos[c - 'A'];
                auto it = st.upper_bound({pos, INT_MAX});
                --it;

                int inicio = it->first;
                int fim = it->second;

                st.erase(it);

                if (inicio < pos)
                    st.insert({inicio, pos - 1});

                if (pos < fim)
                    st.insert({pos + 1, fim});

                s[pos] = '#';
            }
        }
    }
}