#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

string s;
unordered_map<char, int> mp;
vector<string> ans;
int n;

void backtrack(string &curr)
{
    if ((int)curr.size() == n)
    {
        ans.pb(curr);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp[c] > 0)
        {
            mp[c]--;
            curr.push_back(c);
            backtrack(curr);
            curr.pop_back();
            mp[c]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    for (char c : s)
        mp[c]++;
    string curr = "";
    backtrack(curr);
    cout << ans.size() << '\n';
    for (auto &x : ans)
        cout << x << '\n';
    return 0;
}