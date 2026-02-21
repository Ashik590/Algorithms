#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

vector<int> getLPS(string &pattern)
{
    int n = pattern.size();
    vector<int> LPS(n);

    int i = 1;
    LPS[0] = 0;
    int len = 0;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            LPS[i++] = ++len;
        }
        else
        {
            if (len == 0)
                LPS[i++] = 0;
            else
                len = LPS[len - 1];
        }
    }

    return LPS;
}

int find_KMP(string &str, string &pattern)
{
    int j = 0;
    int i = 0;

    int n = str.size();
    int m = pattern.size();

    vector<int> LPS = getLPS(pattern);

    while (i < n)
    {
        if (pattern[j] == str[i])
        {
            i++;
            j++;
        }

        if (j == m)
            return i - j;
        else if (i < n && pattern[j] != str[i])
        {
            if (j > 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }

    return -1;
}

int main()
{
    optimize();

    return 0;
}