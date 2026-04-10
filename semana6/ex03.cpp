#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cedulas = 0;

    cedulas += n / 100;
    n %= 100;

    cedulas += n / 20;
    n %= 20;

    cedulas += n / 10;
    n %= 10;

    cedulas += n / 5;
    n %= 5;

    cedulas += n / 1;
    n %= 1;

    cout << cedulas << "\n";
}