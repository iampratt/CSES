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
    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ms.insert({b, a});
    }
    int res = 0, last = 0;
    for (auto [b, a] : ms)
    {
        if (a >= last)
        {
            res++;
            last = b;
        }
    }
    cout << res;
    return 0;
}