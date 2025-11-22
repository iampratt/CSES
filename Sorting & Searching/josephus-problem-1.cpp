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
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.pb(i);
    for (int i = 1; i <= n; i++)
    {
        dq.pb(dq.front());
        dq.pop_front();
        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}