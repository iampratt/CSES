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
    multiset<int> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto l = k.upper_bound(x);
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
        if (l == k.end())
            k.insert(x);
        else
        {
            k.erase(l);
            k.insert(x);
        }
    }
    cout << k.size();
    return 0;
}