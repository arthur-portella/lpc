#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    int palavras = 0;
    bool dentro = false;

    for (char c : s) {
        if (isalnum(c)) {
            if (!dentro) {
                dentro = true;
                palavras++;
            }
        }
        else
            dentro = false;
    }

    cout << palavras << "\n";
}