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
    int n, x;
    cin >> n >> x;
    if (n < 3)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                ll curr = a[i].first + a[j].first + a[l].first + a[r].first;
                if (curr == x)
                {
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second;
                    return 0;
                }
                else if (curr < x)
                    l++;
                else
                    r--;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}