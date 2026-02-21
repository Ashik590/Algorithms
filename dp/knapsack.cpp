#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;

        arr[i] = {v, w};
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    int sign[n + 1][m + 1] = {0}; // 0 for not taken, 1 for taken

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j < arr[i].second)
            {
                dp[i][j] = dp[i - 1][j];
                sign[i][j] = 0;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].second] + arr[i].first);
                if (dp[i - 1][j] > dp[i - 1][j - arr[i].second] + arr[i].first)
                    sign[i][j] = 0;
                else
                    sign[i][j] = 1;
            }
        }

    for (auto r : dp)
    {
        for (auto c : r)
            cout << c << ' ';
        cout << nl;
    }

    cout << dp[n][m] << nl; // optimal knapsack score

    // Printing the taken ones
    vector<pair<int, int>> taken;
    int i = n, j = m;

    while (i && j)
    {
        if (sign[i][j])
        {
            taken.push_back(arr[i]);
            j -= arr[i].second;
        }
        i--;
    }

    for (auto e : taken)
        cout << e.first << ' ' << e.second << nl;
    cout << nl;

    return 0;
}