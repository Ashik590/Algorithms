#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long


// LIS implementation with O(nlogn)

int lowerBound(vector<pair<int, int>> &trail, int &val)
{
    int ind = -1;

    int l = 0, r = trail.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (trail[mid].first >= val)
        {
            ind = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ind;
}

void LIS_fast(vector<int> &arr, vector<int> &dp, vector<int> &prev)
{

    int n = arr.size();
    vector<pair<int, int>> trail;

    trail.push_back({arr[0], 0});

    for (int i = 1; i < n; i++)
    {
        int ind = lowerBound(trail, arr[i]);

        if (ind == -1)
        {
            trail.push_back({arr[i], i});
            dp[i] = trail.size();
            prev[i] = trail[trail.size() - 2].second;
        }
        else
        {
            dp[i] = ind + 1;
            if (ind == 0)
                prev[i] = -1;
            else
                prev[i] = trail[ind - 1].second;

            trail[ind].first = arr[i];
            trail[ind].second = i;
        }
    }
}

vector<int> getLIS(vector<int> &arr, vector<int> &dp, vector<int> &prev) // same as naive dp
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

    LIS_fast(arr, dp, prev);

    cout << *max_element(dp.begin(), dp.end()) << nl;
    vector<int> lis = getLIS(arr, dp, prev);

    return 0;
}