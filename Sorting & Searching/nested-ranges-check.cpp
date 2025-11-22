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
    vector<vector<ll>> ran(n, vector<ll>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> ran[i][0] >> ran[i][1];
        ran[i][2] = i;
    }
    sort(all(ran), [](auto &a, auto &b)
         {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0]; });
    vector<int> contains(n, 0), contained(n, 0);
    ll max_r = 0;
    for (int i = 0; i < n; i++)
    {
        if (ran[i][1] <= max_r)
            contained[ran[i][2]] = 1;
        max_r = max(max_r, ran[i][1]);
    }
    ll min_r = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ran[i][1] >= min_r)
            contains[ran[i][2]] = 1;
        min_r = min(min_r, ran[i][1]);
    }
    for (int x : contains)
        cout << x << " ";
    cout << "\n";
    for (int x : contained)
        cout << x << " ";
    return 0;
}