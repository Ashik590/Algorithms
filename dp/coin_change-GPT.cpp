#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    const int INF = 1e9;

    // dp[x] = minimum coins needed to make amount x
    vector<int> dp(amount + 1, INF);

    dp[0] = 0; // base case

    for (int x = 1; x <= amount; x++)
    {
        for (int coin : coins)
        {
            if (coin <= x)
            {
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }

    return (dp[amount] == INF) ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl; // Output: 3 (5+5+1)
}
