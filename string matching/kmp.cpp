#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

vector<int> getPrefixFunc(string pattern)
{
    int m = pattern.size();
    vector<int> prefFunc(m);

    int len = 0;
    prefFunc[0] = 0;

    for (int i = 1; i < m;)
    {
        if (pattern[i] == pattern[len])
        {
            prefFunc[i] = ++len;
            i++;
        }
        else if (len)
            len = prefFunc[len - 1];
        else
        {
            prefFunc[i] = 0;
            i++;
        }
    }

    return prefFunc;
}

vector<int> string_match_KMP(string s, string pattern)
{
    vector<int> pos;
    vector<int> prefixFunc = getPrefixFunc(pattern);
    int n = s.size();
    int m = pattern.size();

    int j = 0;

    for (int i = 0; i < n;)
    {
        if (pattern[j] == s[i])
        {
            i++;
            j++;

            if (j == m)
            {
                pos.push_back(i - m);
                j = prefixFunc[j - 1];
            }
        }
        else
        {
            if (j)
                j = prefixFunc[j - 1];
            else
                i++;
        }
    }

    return pos;
}

int main()
{
    string s = "wor";
    string pattern = "wor";

    vector<int> pos = string_match_KMP(s, pattern);

    for (auto e : pos)
        cout << e << ' ';
    cout << nl;

    return 0;
}