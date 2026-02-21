#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &a)
{
    int n = a.size();

    long long prefixSum = 0;      // current prefix sum
    long long minPrefix = 0;      // minimum prefix sum seen so far
    long long maxSum = LLONG_MIN; // answer

    for (int i = 0; i < n; i++)
    {
        prefixSum += a[i];

        // best subarray ending at i
        maxSum = max(maxSum, prefixSum - minPrefix);

        // update minimum prefix
        minPrefix = min(minPrefix, prefixSum);
    }

    return maxSum;
}

int main()
{
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(a) << endl; // Output: 6
}
