#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ind[arr[i]] = i;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++)
        if (ind[i + 1] < ind[i])
            rounds++;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int u = arr[a];
        int v = arr[b];
        vector<int> check = {u - 1, u, v - 1, v};
        for (int x : check)
            if (ind[x] < ind[x - 1])
                rounds--;
        swap(arr[a], arr[b]);
        nd[u] = b;
        ind[v] = a;
        for (int x : check)
            if (ind[x] < ind[x - 1])
                rounds++;
        cout << rounds << "\n";
    }
    return 0;
}