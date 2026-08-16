#include <bits/stdc++.h>
using namespace std;

vector<long long> pre(string Pattern){
    vector<long long> lps(Pattern.size());

    for (int i=1, j=0;i<Pattern.size();i++) {
        while(j>0 and Pattern[j]!=Pattern[i]) {
            j = lps[j-1];
        }
        if (Pattern[j]==Pattern[i]) 
            j++;
        lps[i] = j;
    }

    return lps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    vector<long long> lps = pre(s);
    vector<int> resp;

    int x = lps[s.size() - 1];

    while (x > 0) {
        resp.push_back(x);
        x = lps[x - 1];
    }

    reverse(resp.begin(), resp.end());

    for (int x : resp)
        cout << x << " ";

    cout << '\n';
}
