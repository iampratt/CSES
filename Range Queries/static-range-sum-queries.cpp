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
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        pre[i + 1] = pre[i] + x[i];
    }
    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << '\n';
    }
    return 0;
}