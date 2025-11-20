#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int booth(string s)
{
    s += s;
    int i = 0, j = 1, k = 0, n = s.size();
    while (i < n / 2 && j < n / 2 && k < n / 2)
    {
        if (s[i + k] == s[j + k])
            k++;
        else if (s[i + k] < s[j + k])
        {
            j += k + 1;
            if (j <= i)
                j = i + 1;
            k = 0;
        }
        else
        {
            i += k + 1;
            if (i <= j)
                i = j + 1;
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int x = booth(s);
    cout << s.substr(x) + s.substr(0, x);
    return 0;
}