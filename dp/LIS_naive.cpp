#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

// LIS implementation with O(n^2)

int recurseLIS(vector<int> &arr, vector<int> &dp, vector<int> &prev, int ind)
{
    if (dp[ind] != -1)
        return dp[ind];

    int maxLIS = 1;
    int maxLISind = -1;

    for (int i = ind - 1; i >= 0; i--)
    {
        if (maxLIS < 1 + recurseLIS(arr, dp, prev, i) && arr[ind] > arr[i])
        {
            maxLIS = 1 + recurseLIS(arr, dp, prev, i);
            maxLISind = i;
        }
    }

    dp[ind] = maxLIS;
    prev[ind] = maxLISind;

    return maxLIS;
}

vector<int> getLIS(vector<int> &arr, vector<int> &dp, vector<int> &prev)
{
    int maxLIS = 0, maxLISind = 0;

    for (int i = 0; i < dp.size(); i++)
    {
        if (maxLIS < dp[i])
        {
            maxLIS = dp[i];
            maxLISind = i;
        }
    }

    vector<int> LIS;
    int ind = maxLISind;

    while (ind != -1)
    {
        LIS.push_back(arr[ind]);
        ind = prev[ind];
    }

    reverse(LIS.begin(), LIS.end());

    return LIS;
}

int main()
{
    optimize();

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n, -1);
    dp[0] = 1;

    vector<int> prev(n, -1);

    recurseLIS(arr, dp, prev, n - 1);

    // for (auto e : prev)
    // {
    //     cout << e << ' ';
    // }
    // cout << nl;

    vector<int> LIS = getLIS(arr, dp, prev);

    for (auto e : LIS)
    {
        cout << e << ' ';
    }
    cout << nl;

    return 0;
}