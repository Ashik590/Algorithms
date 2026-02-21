#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

int recurse(vector<pair<int, int>> &mats, vector<vector<int>> &dp, vector<vector<int>> &track, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int cost = INT_MAX, minInd;
    for (int k = i; k < j; k++)
    {
        int calc = recurse(mats, dp, track, i, k) + recurse(mats, dp, track, k + 1, j) + mats[i].first * mats[k].second * mats[j].second;
        if (cost > calc)
        {
            cost = calc;
            minInd = k;
        }
    }

    dp[i][j] = cost;
    track[i][j] = minInd;
    return cost;
}

void printPath(vector<char> &matsSymbol, vector<vector<int>> &track, int i, int j)
{
    if (i == j)
        cout << matsSymbol[i];
    else
    {
        cout << '(';

        printPath(matsSymbol, track, i, track[i][j]);
        printPath(matsSymbol, track, track[i][j] + 1, j);

        cout << ')';
    }
}

int main()
{
    optimize();

    int n = 5;

    vector<char> matsSymbol = {'_', 'A', 'B', 'C', 'D', 'E'};
    vector<pair<int, int>> mats = {
        {0, 0}, {10, 5}, {5, 1}, {1, 10}, {10, 2}, {2, 10}};

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> track(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    recurse(mats, dp, track, 1, n);

    cout << dp[1][n] << nl;
    
    printPath(matsSymbol, track, 1, n);
    cout << nl;

    return 0;
}