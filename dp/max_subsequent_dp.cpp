#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

vector<int> arr = {4, 5, 9, 2, 3};
int dp[100];

int recurse(int ind)
{
    if (dp[ind] != -1)
        return dp[ind];

    int op_ans = max((recurse(ind - 2) + arr[ind]), recurse(ind - 1));

    dp[ind] = op_ans;

    return op_ans;
}

void printpath(int ind)
{
    if (ind >= 0)
    {
        if (dp[ind] == dp[ind - 1])
            printpath(ind - 1);
        else
        {
            printpath(ind - 2);
            cout << arr[ind] << ' ';
        }
    }
}

int main()
{
    optimize();

    for (int i = 0; i < 100; i++)
    {
        dp[i] = -1;
    }

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    recurse(arr.size() - 1);
    cout << nl << dp[arr.size() - 1] << nl;

    printpath(arr.size() - 1);
    cout << nl;

    return 0;
}