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
    vector<int> ind(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ind[x - 1] = i;
    }
    int res = 1;
    for (int i = 1; i < n; i++)
        if (ind[i] < ind[i - 1])
            res++;
    cout << res;
    return 0;
}