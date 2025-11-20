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
        int x, y;
        cin >> x >> y;
        int z = max(x, y);
        ll z2 = 1LL * (z - 1) * (z - 1);
        ll res;
        if (z & 1)
        {
            if (z == x)
                res = z2 + y;
            else
                res = z2 + 2 * z - x;
        }
        else
        {
            if (z == y)
                res = z2 + x;
            else
                res = z2 + 2 * z - y;
        }
        cout << res << '\n';
    }
    return 0;
}