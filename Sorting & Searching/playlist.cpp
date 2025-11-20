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
    vector<int> k(n);
    set<int> s;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    int i = 0, j = 0, res = 0;
    while (i < n)
    {
        while (j < n && s.count(k[j]) == 0)
        {
            s.insert(k[j]);
            j++;
        }
        res = max(res, j - i);
        s.erase(k[i]);
        i++;
    }
    cout << res;
    return 0;
}