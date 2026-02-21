#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

vector<int> getPieces(vector<int> &cuts, int length)
{
    int n = length;
    vector<int> pieces;

    while (n)
    {
        pieces.push_back(cuts[n]);
        n -= cuts[n];
    }

    return pieces;
}

int main()
{
    optimize();

    int n, l;
    cin >> n >> l;

    vector<int> revenue(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> revenue[i];

    vector<int> dp(l + 1, 0), cuts(l + 1, 0);
    dp[1] = revenue[1];
    cuts[1] = 1;

    for (int i = 2; i <= l; i++)
        for (int j = 1; j <= min(i, n); j++)
        {
            if (dp[i] < revenue[j] + dp[i - j])
            {
                dp[i] = revenue[j] + dp[i - j];
                cuts[i] = j;
            }
        }

    // for (int i = 1; i <= l; i++)
    //     cout << dp[i] << ' ';
    // cout << nl;

    cout << dp[l] << nl;

    vector<int> pieces = getPieces(cuts, l);

    for (auto e : pieces)
        cout << e << ' ';
    cout << nl;

    return 0;
}