#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

vector<int> getMaxInterval(vector<int> prev, vector<int> arr, int ind)
{
    vector<int> interval;
    while (prev[ind])
    {
        interval.push_back(arr[ind]);
        ind--;
    }

    interval.push_back(arr[ind]);
    reverse(interval.begin(), interval.end());

    return interval;
}

int main()
{
    optimize();

    vector<int> arr = {2, -5, 9, -3, 1, 7, -15, 2, 3};
    int n = arr.size();

    vector<int> dp(n, -1); /* max sum interval ending at ith element */
    vector<int> prev(n);
    /* 0 or 1, 0 meaning the max interval starts from ith elem and 1 means the max interval does not start from ith elem */

    dp[0] = arr[0];
    prev[0] = 0;

    for (int i = 1; i < n; i++)
        if (dp[i - 1] + arr[i] < arr[i])
        {
            dp[i] = arr[i];
            prev[i] = 0;
        }
        else
        {
            dp[i] = dp[i - 1] + arr[i];
            prev[i] = 1;
        }

    vector<int> interval = getMaxInterval(prev, arr, max_element(dp.begin(), dp.end()) - dp.begin());

    for (auto e : interval)
        cout << e << ' ';
    cout << nl;

    return 0;
}