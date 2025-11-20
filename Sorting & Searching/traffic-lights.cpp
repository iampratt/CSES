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
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> dist;
    lights.insert({0, x});
    dist.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto l = lights.upper_bound(p);
        l--;
        auto r = lights.upper_bound(p);
        dist.erase(dist.find(*r - *l));
        dist.insert(*r - p);
        dist.insert(p - *l);
        lights.insert(p);
        cout << *dist.rbegin() << " ";
    }
    return 0;
}