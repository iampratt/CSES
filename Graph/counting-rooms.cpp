#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

int n, m;
vector<string> grid;

bool e(int i, int j)
{
    return i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == '.';
}

void dfs(int i, int j)
{
    grid[i][j] = '#';
    int dir[] = {1, 0, -1, 0, 1};
    for (int d = 0; d < 4; d++)
    {
        if (e(i + dir[d], j + dir[d + 1]))
            dfs(i + dir[d], j + dir[d + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (e(i, j))
            {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}