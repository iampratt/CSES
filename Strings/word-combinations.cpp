#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

struct TrieNode
{
    struct TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

TrieNode *root = new TrieNode();

bool search(string str)
{
    TrieNode *curr = root;
    for (char c : str)
    {
        if (curr->child[c - 'a'] == nullptr)
            return false;
        curr = curr->child[c - 'a'];
    }
    return curr->isEnd;
}

void insert(string str)
{
    TrieNode *curr = root;
    for (char c : str)
    {
        if (curr->child[c - 'a'] == nullptr)
            curr->child[c - 'a'] = new TrieNode();
        curr = curr->child[c - 'a'];
    }
    curr->isEnd = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size(), t;
    cin >> t;
    vector<string> sub(t);
    for (int i = 0; i < t; i++)
    {
        cin >> sub[i];
        insert(sub[i]);
    }
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        TrieNode *curr = root;
        for (int j = i; j < n; j++)
        {
            if (curr->child[s[j] - 'a'] == nullptr)
                break;
            curr = curr->child[s[j] - 'a'];
            if (curr->isEnd)
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }
    cout << dp[0];
    return 0;
}