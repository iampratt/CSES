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
    // vector<vector<int>> a(n, vector<int>(2));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (mp.find(x - a) != mp.end())
        {
            cout << mp[x - a] << " " << i + 1;
            return 0;
        }
        mp[a] = i + 1;
    }
    // sort(all(a));
    // int i = 0, j = n - 1;
    // while (i < j)
    // {
    //     ll sum = a[i][0] + a[j][0];
    //     if (sum == x)
    //     {
    //         cout << a[i][1] << " " << a[j][1];
    //         return 0;
    //     }
    //     else if (sum < x)
    //         i++;
    //     else
    //         j--;
    // }
    cout << "IMPOSSIBLE";
    return 0;
}