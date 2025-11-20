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
    for (int i = 1; i <= n; i++)
    {
        ll total = 1LL * (i * i) * (i * i - 1) / 2;
        ll attack_ways = 1LL * 4 * (i - 1) * (i - 2);
        cout << total - attack_ways << '\n';
    }
    return 0;
}