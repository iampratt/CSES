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
    int n;
    cin >> n;
    ll total = 1LL * n * (n + 1) / 2;
    if (total & 1)
        cout << "NO";
    else
    {
        cout << "YES" << '\n';
        vector<int> s1, s2;
        ll target = total / 2;
        for (int i = n; i > 0; i--)
        {
            if (target >= i)
            {
                s1.pb(i);
                target -= i;
            }
            else
                s2.pb(i);
        }
        cout << s1.size() << '\n';
        for (int i : s1)
            cout << i << " ";
        cout << '\n';
        cout << s2.size() << '\n';
        for (int i : s2)
            cout << i << " ";
    }
    return 0;
}