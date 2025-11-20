#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(all(p));
    int i = 0, j = n - 1, res = 0;
    while (i <= j)
    {
        if (p[i] + p[j] <= x)
        {
            i++;
            j--;
        }
        else
            j--;
        res++;
    }
    cout << res;
    return 0;
}