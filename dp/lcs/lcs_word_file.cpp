#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

int n, m;
vector<string> str1, str2;

vector<string> lcs(vector<vector<pair<int, int>>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j].first = dp[i - 1][j - 1].first + 1;
                dp[i][j].second = 0;
            }
            else
            {
                dp[i][j].first = max(dp[i][j - 1].first, dp[i - 1][j].first);
                if (dp[i][j - 1].first > dp[i - 1][j].first)
                    dp[i][j].second = 1;
                else
                    dp[i][j].second = 2;
            }
        }
    }

    vector<string> target;

    int i = n, j = m;
    while (i && j)
    {
        if (dp[i][j].second == 0)
        {
            target.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j].second == 1)
            j--;
        else
            i--;
    }

    reverse(target.begin(), target.end());
    return target;
}

vector<string> split(string s)
{
    vector<string> strs;

    string temp = "";

    for (auto e : s)
    {
        if (e == ' ')
        {
            strs.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(e);
    }
    strs.push_back(temp);

    return strs;
}

int main()
{
    optimize();

    string s1, s2;

    // getline(cin, s1);
    // getline(cin, s2);

    ifstream inputFile("s1.txt");
    getline(inputFile, s1);
    inputFile.close();

    ifstream inputFile1("s2.txt");
    getline(inputFile1, s2);
    inputFile1.close();

    str1 = split(s1);
    str2 = split(s2);

    n = str1.size();
    m = str2.size();
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0].first = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i].first = 0;
    }

    vector<string> lcsStr = lcs(dp);
    for (auto e : lcsStr)
    {
        cout << e << ' ';
    }
    cout << nl;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j].first << ',' << dp[i][j].second << "  ";
    //     }
    //     cout << nl;
    // }

    return 0;
}