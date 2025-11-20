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
    int n;
    cin >> n;
    vector<int> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int l = upper_bound(all(k), x) - k.begin();
        // finding upper bound using binary search
        //  int l = 0, r = k.size();
        //  while (l < r)
        //  {
        //      int mid = (l + r) / 2;
        //      if (k[mid] > x)
        //          r = mid;
        //      else
        //          l = mid + 1;
        //  }
        if (l == k.size())
            k.push_back(x);
        else
            k[l] = x;
    }
    cout << k.size();
    return 0;
}