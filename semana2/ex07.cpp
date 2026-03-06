#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++) {
        long long aux;
        cin >> aux;

        if (!s.empty() && s.top() == aux % 2) {
            s.push(aux % 2);
        } else if (!s.empty() && s.top() == aux % 2) {
            s.pop();
        }
    }
    
    if(s.size() <= 1)
        cout << "YES\n";
    else 
        cout << "NO\n";
}
