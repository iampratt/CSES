#include <bits/stdc++.h>
using namespace std;

#define ll long long

void hanoi(int n, int from, int to, int aux)
{
    if (n == 0)
        return;
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, aux, to, from);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (!n)
        return 0;
    ll k = (1LL << n) - 1;
    cout << k << "\n";
    hanoi(n, 1, 3, 2);
    return 0;
}