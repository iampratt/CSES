#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll moves = (a + b) / 3;
        if ((a + b) % 3 == 0 && min(a, b) >= moves)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}