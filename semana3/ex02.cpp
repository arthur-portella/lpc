#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int tempo_util = 240 - k;

    int i = 1, problems = 0;
    while (true) {
        tempo_util -= 5 * i++;

        if (tempo_util < 0 || i - 1 > n)
            break;
        else
            problems++;
    }

    cout << problems << "\n";
}