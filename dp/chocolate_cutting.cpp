#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

int n, m;

int recurse(vector<vector<int>> &arr, vector<vector<int>> &dp, int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];

    int profit = arr[x][y];

    for (int i = 1; i < x; i++)
        profit = max(profit, recurse(arr, dp, i, y) + recurse(arr, dp, x - i, y));

    for (int i = 1; i < y; i++)
        profit = max(profit, recurse(arr, dp, x, i) + recurse(arr, dp, x, y - i));

    dp[x][y] = profit;

    return profit;
}

int main()
{
    optimize();

    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    cout << recurse(arr, dp, n, m);

    return 0;
}