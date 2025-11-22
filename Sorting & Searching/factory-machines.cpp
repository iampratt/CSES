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
    int n, t;
    cin >> n >> t;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];
    ll low = 0, high = 1e18, res = 1e18;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll prod = 0;
        for (int i : time)
        {
            prod += mid / i;
            if (prod >= t)
                break;
        }
        if (prod >= t)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << res;
    return 0;
}