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
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;
    sort(all(tasks));
    ll time = 0, reward = 0;
    for (auto [ct, cd] : tasks)
    {
        time += ct;
        reward += (cd - time);
    }
    cout << reward;
    return 0;
}