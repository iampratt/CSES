#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

vector<string> board(8);
vector<bool> colUsed(8, false);
vector<bool> diag1(16, false);
vector<bool> diag2(16, false);
ll ans = 0;

void dfs(int r)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (board[r][c] == '.' &&
            !colUsed[c] &&
            !diag1[r + c] &&
            !diag2[r - c + 7])
        {
            colUsed[c] = diag1[r + c] = diag2[r - c + 7] = true;
            dfs(r + 1);
            colUsed[c] = diag1[r + c] = diag2[r - c + 7] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    dfs(0);
    cout << ans << "\n";
    return 0;
}