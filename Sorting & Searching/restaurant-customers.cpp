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
    int n;
    cin >> n;
    multiset<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.insert({a, 1});
        pq.insert({b, -1});
    }
    int curr = 0, res = 0;
    for (auto it : pq)
    {
        curr += it.second;
        res = max(res, curr);
    }
    cout << res;
    return 0;
}