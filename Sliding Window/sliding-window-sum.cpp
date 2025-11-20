#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        if (i == 0)
            arr[i] = x;
        else
            arr[i] = (arr[i - 1] * a + b) % c;
    ll sum = 0, xsum;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    xsum = sum;
    for (int i = 0; i < n - k; i++)
    {
        sum = sum - arr[i] + arr[i + k];
        xsum ^= sum;
    }
    cout << xsum;
    return 0;
}