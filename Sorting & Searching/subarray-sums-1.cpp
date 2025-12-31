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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0, res = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        sum += a[r];
        while (sum > x)
        {
            sum -= a[l];
            l++;
        }
        if (sum == x)
            res++;
        r++;
    }
    cout << res;

    return 0;
}