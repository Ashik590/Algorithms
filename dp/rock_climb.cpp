#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

int n, m;
// 2 8 9 5 8
// 4 4 6 2 3
// 5 7 5 6 1
// 3 2 5 4 8

// 5 1 1
// 9 1 1
// 9 1 1
int recurse(vector<vector<int>> &dp, vector<vector<int>> &arr, int i, int j)
{

    if (dp[i][j] != -1)
        return dp[i][j];

    int cost;

    cost = arr[i][j] + min({j == 0 ? INT_MAX : recurse(dp, arr, i + 1, j - 1), recurse(dp, arr, i + 1, j), j == m - 1 ? INT_MAX : recurse(dp, arr, i + 1, j + 1)});

    dp[i][j] = cost;

    return cost;
}

void printPath(vector<vector<int>> &dp, vector<vector<int>> &arr, int i, int j)
{
    cout << arr[i][j] << nl;

    if (i == n - 1)
        return;

    int mn = min({j == 0 ? INT_MAX : dp[i + 1][j - 1], dp[i + 1][j], j == m - 1 ? INT_MAX : dp[i + 1][j + 1]});

    if (j && mn == dp[i + 1][j - 1])
        printPath(dp, arr, i + 1, j - 1);
    else if (j != m - 1 && mn == dp[i + 1][j + 1])
        printPath(dp, arr, i + 1, j + 1);
    else
        printPath(dp, arr, i + 1, j);
}

int main()
{
    optimize();

    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }

        if (i == n - 1)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        recurse(dp, arr, 0, i);
    }

    // for (auto r : dp)
    // {
    //     for (auto e : r)
    //     {
    //         cout << e << ' ';
    //     }
    //     cout << nl;
    // }

    cout << nl;

    // Printing PAth

    int minInd, minE = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        if (minE > dp[0][i])
        {
            minE = dp[0][i];
            minInd = i;
        }
    }

    printPath(dp, arr, 0, minInd);

    return 0;
}