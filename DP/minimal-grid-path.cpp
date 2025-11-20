#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int dir[] = {1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<int>> path(n, vector<int>(n, -1));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> q, diag;
    q.push({0, 0});
    vis[0][0] = true;
    string res = "";
    res += grid[0][0];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int resLen = 1e9;
        vector<pair<int, int>> local;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 2; d++)
            {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    path[nx][ny] = d;
                    resLen = min(resLen, grid[nx][ny] - 'A');
                    local.pb({nx, ny});
                }
            }
        }
        for (auto [x, y] : local)
            if (resLen == grid[x][y] - 'A')
                q.push({x, y});
        res += char(resLen + 65);
    }
    cout << res.substr(0, res.size() - 1);
    return 0;
}