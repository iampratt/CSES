#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

vector<int> kmp(string s)
{
    vector<int> lps(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> lps = kmp(s);
    vector<int> borders;
    int i = lps[s.size() - 1];
    while (i > 0)
    {
        borders.pb(i);
        i = lps[i - 1];
    }
    sort(all(borders));
    for (int b : borders)
        cout << b << " ";
    return 0;
}