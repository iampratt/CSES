#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

vector<int> manacher(string s)
{
    string s2 = "#";
    for (char c : s)
    {
        s2 += c;
        s2 += '#';
    }
    int l = 0, r = 0, maxLen = 0, start = -1;
    vector<int> p(s2.size(), 0);
    for (int i = 1; i < s2.size(); i++)
    {
        int mirror = l + r - i;
        if (i < r)
            p[i] = min(r - i, p[mirror]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < s2.size() &&
               s2[i - p[i] - 1] == s2[i + p[i] + 1])
            p[i]++;
        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> p = manacher(s);
    vector<int> res(s.size(), 1);
    for (int i = 1; i < p.size(); i++)
    {
        int l = (i - p[i]) / 2;
        int r = (i + p[i]) / 2 - 1;
        if (l < r)
            res[r] = max(res[r], r - l + 1);
    }
    int maxi = res[s.size() - 1];
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (res[i] < maxi - 2)
        {
            res[i] = maxi - 2;
            maxi -= 2;
        }
        else
            maxi = res[i];
    }
    for (int i : res)
        cout << i << " ";
    return 0;
}
