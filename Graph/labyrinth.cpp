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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int dir[] = {1, 0, -1, 0, 1};
    string dirString = "DLUR";
    vector<vector<int>> path(n, vector<int>(m, -1));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                start = make_pair(i, j);
            if (grid[i][j] == 'B')
                end = make_pair(i, j);
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        if (i == end.first && j == end.second)
            break;
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] == '#')
                continue;
            grid[ni][nj] = '#';
            q.push(make_pair(ni, nj));
            path[ni][nj] = d;
        }
    }
    if (grid[end.first][end.second] == '#')
    {
        cout << "YES" << '\n';
        string p = "";
        while (start != end)
        {
            int d = path[end.first][end.second];
            p += dirString[d];
            end.first -= dir[d];
            end.second -= dir[d + 1];
        }
        reverse(all(p));
        cout << p.size() << '\n';
        cout << p;
    }
    else
        cout << "NO";
    return 0;
}