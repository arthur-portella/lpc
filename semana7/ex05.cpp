#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    deque<long long> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    long long taro = 0, jiro = 0;

    while (!d.empty()) {
        long long inicio, fim;
        inicio = d.front();
        fim = d.back();

        if (inicio >= fim) {
            taro += inicio;
            d.pop_front();
        } else {
            taro += fim;
            d.pop_back();
        }

        if (!d.empty()) {
            inicio = d.front();
            fim = d.back();

            if (inicio >= fim) {
                jiro += inicio;
                d.pop_front();
            } else {
                jiro += fim;
                d.pop_back();
            }
        }
    }

    cout << taro - jiro << "\n";
}