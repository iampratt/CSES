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
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;
    // If any char exceeds limit => impossible
    for (int f : freq)
    {
        if (f > (n + 1) / 2)
        {
            cout << -1;
            return 0;
        }
    }
    string ans = "";
    char last = '#';
    for (int i = 0; i < n; i++)
    {
        bool placed = false;
        for (int c = 0; c < 26; c++)
        {
            if (freq[c] == 0)
                continue;
            if (last == char('A' + c))
                continue;
            freq[c]--;
            bool ok = true;
            int maxFreq = *max_element(freq.begin(), freq.end());
            if (maxFreq > (n - i - 1 + 1) / 2)
                ok = false;
            if (ok)
            {
                ans += char('A' + c);
                last = char('A' + c);
                placed = true;
                break;
            }
            freq[c]++;
        }
        if (!placed)
        {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}