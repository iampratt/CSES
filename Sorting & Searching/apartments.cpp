#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, res = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            res++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    cout << res;
    return 0;
}