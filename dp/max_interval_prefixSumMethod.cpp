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

    vector<int> arr = {2, -5, 9, -3, 1, 7, -15, 2, 3};
    int n = arr.size();

    vector<int> pre(n + 1, 0);

    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i - 1];

    int mnInd = 0;
    int mxSum = -INT_MAX;

    pair<int, int> interval;

    for (int i = 1; i <= n; i++)
    {
        if (mxSum < pre[i] - pre[mnInd])
        {
            mxSum = pre[i] - pre[mnInd];

            interval.first = mnInd;
            interval.second = i;
        }

        if (pre[mnInd] > pre[i])
            mnInd = i;
    }

    cout << mxSum << nl;
    cout << interval.first + 1 << ' ' << interval.second << nl;

    return 0;
}