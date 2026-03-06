#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string linha;

    while (getline(cin, linha)) {
        stringstream ss(linha);
        long long x;
        
        stack<long long> tamanho;
        stack<long long> soma;

        bool ok = true;
        
        while (ss >> x) {
            
            if (x < 0) {
                tamanho.push(-x);
                soma.push(0);
            } else {
                if (tamanho.empty() || tamanho.top() != x) {
                    ok = false;
                    break;
                }

                if (soma.top() >= x) {
                    ok = false;
                    break;
                }

                long long valor = x;

                tamanho.pop();
                soma.pop();

                if (!soma.empty())
                    soma.top() += valor;
            }

        }

        if (!tamanho.empty())
            ok = false;

        if (ok)
            cout << ":-) Matrioshka!\n";
        else 
            cout << ":-( Try again.\n";
    }
}