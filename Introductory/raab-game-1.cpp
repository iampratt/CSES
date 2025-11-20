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
        ll n, a, b;
        cin >> n >> a >> b;
        if ((a + b) > n || ((a + b) > 0 && (a == 0 || b == 0)))
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        ll draws = n - (a + b);
        ll limit = a + b;
        // Player 1
        for (int i = (b + 1); i <= limit; i++)
            cout << i << " ";
        for (int i = 1; i <= b; i++)
            cout << i << " ";
        for (int i = limit + 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
        // Player 2
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}