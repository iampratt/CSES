#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m;
vector<string> grid;
vector<vector<int>> ad, md;
pair<int, int> al;
vector<pair<int, int>> ml;
vector<int> dir = {1, 0, -1, 0, 1};
string dirSt = "DLUR";
vector<vector<int>> path;

void bfs(vector<pair<int, int>> coord, vector<vector<int>> &dist, bool human = false)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (auto c : coord)
    {
        q.push(c);
        vis[c.first][c.second] = true;
    }
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '.' && !vis[ni][nj])
            {
                vis[ni][nj] = true;
                dist[ni][nj] = min(dist[ni][nj], dist[i][j] + 1);
                q.push(make_pair(ni, nj));
                if (human)
                    path[ni][nj] = d;
            }
        }
    }
}

void printPath(int i, int j)
{
    cout << "YES" << '\n';
    string res = "";
    while (make_pair(i, j) != al)
    {
        int d = path[i][j];
        res += dirSt[d];
        i -= dir[d];
        j -= dir[d + 1];
    }
    reverse(all(res));
    cout << res.size() << '\n';
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    grid.resize(n);
    ad.resize(n, vector<int>(m, 1e9));
    md.resize(n, vector<int>(m, 1e9));
    path.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                al = make_pair(i, j);
                ad[i][j] = 0;
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'M')
            {
                ml.pb(make_pair(i, j));
                md[i][j] = 0;
                grid[i][j] = '.';
            }
        }
    }
    bfs({al}, ad, true);
    bfs(ml, md);
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '.' && ad[i][0] < md[i][0])
        {
            printPath(i, 0);
            return 0;
        }
        if (grid[i][m - 1] == '.' && ad[i][m - 1] < md[i][m - 1])
        {
            printPath(i, m - 1);
            return 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == '.' && ad[0][i] < md[0][i])
        {
            printPath(0, i);
            return 0;
        }
        if (grid[n - 1][i] == '.' && ad[n - 1][i] < md[n - 1][i])
        {
            printPath(n - 1, i);
            return 0;
        }
    }
    cout << "NO";
    return 0;
}