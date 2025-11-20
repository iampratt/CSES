#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;
    int oddCount = 0;
    char oddChar = 0;
    for (auto [c, i] : mp)
        if (i & 1)
            oddCount++, oddChar = c;
    if (oddCount > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string left = "", mid = "";
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (mp.count(c))
        {
            int cnt = mp[c];
            if (cnt & 1)
                mid.append(cnt, c);
            else
                left.append(cnt / 2, c);
        }
    }
    string right = left;
    reverse(all(right));
    cout << left << mid << right << "\n";
    return 0;
}