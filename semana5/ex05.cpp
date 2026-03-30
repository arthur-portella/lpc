#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        priority_queue<long long> esq;
        priority_queue<long long, vector<long long>, greater<long long>> dir;

        long long n;
        while (cin >> n && n != 0) {
            if (n > 0) {
                esq.push(n);

                dir.push(esq.top());
                esq.pop();

                if (dir.size() > esq.size()) {
                    esq.push(dir.top());
                    dir.pop();
                }
            } else if(n == -1) {
                cout << esq.top() << "\n";
                esq.pop();

                if (dir.size() > esq.size()) {
                    esq.push(dir.top());
                    dir.pop();
                }
            }
        }

    }

}