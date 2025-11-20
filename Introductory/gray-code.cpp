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
    int n;
    cin >> n;
    // vector<string> gray;
    // gray.pb("0");
    // gray.pb("1");
    // for (int i = 2; i <= n; i++)
    // {
    //     int size = gray.size();
    //     // reflect
    //     for (int j = size - 1; j >= 0; j--)
    //         gray.pb(gray[j]);
    //     // prefix 0 to first half
    //     for (int j = 0; j < size; j++)
    //         gray[j] = "0" + gray[j];
    //     // prefix 1 to second half
    //     for (int j = size; j < 2 * size; j++)
    //         gray[j] = "1" + gray[j];
    // }
    // for (string &s : gray)
    //     cout << s << "\n";

    int total = 1 << n; // 2^n
    for (int i = 0; i < total; i++)
    {
        // gray code = i ^ (i >> 1)
        int g = i ^ (i >> 1);
        // print g as n-bit binary
        for (int bit = n - 1; bit >= 0; bit--)
            cout << ((g >> bit) & 1);
        cout << "\n";
    }
    return 0;
}