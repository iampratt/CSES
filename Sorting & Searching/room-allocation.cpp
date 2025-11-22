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
    vector<vector<ll>> customers(n, vector<ll>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }
    sort(all(customers));
    multiset<pair<ll, int>> ms; // {departure_day, room_number}
    vector<int> ans(n);
    int rooms = 0;
    for (auto &c : customers)
    {
        ll arr = c[0];
        ll dep = c[1];
        int idx = c[2];
        auto it = ms.lower_bound({arr, 0});
        if (it == ms.begin())
        {
            rooms++;
            ans[idx] = rooms;
            ms.insert({dep, rooms});
        }
        else
        {
            it--;
            int room_no = it->second;
            ms.erase(it);
            ans[idx] = room_no;
            ms.insert({dep, room_no});
        }
    }
    cout << rooms << '\n';
    for (int x : ans)
        cout << x << " ";
    return 0;
}