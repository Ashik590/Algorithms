// Finite Automata String Matching Algorithm - O(n + m^3)

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

bool isSufPref(string &pattern, string &str, int k)
{
    // cout << pattern << nl;
    // cout << str << nl;
    // cout << k << nl;
    // cout << nl;
    bool cond = 1;
    int sz = str.size();

    for (int i = 0; i < k; i++)
        if (pattern[i] != str[sz - k + i])
        {
            cond = 0;
            break;
        }

    return cond;
}

vector<vector<int>> create_transition_func(string pattern)
{
    int m = pattern.size();

    vector<vector<int>> table(m + 1, vector<int>(256));

    string str = "";
    for (int q = 0; q <= m; q++)
    {
        if (q)
            str += pattern[q - 1];

        for (int a = 0; a < 256; a++)
        {
            int k = min(m, q + 1);

            string newStr = str + (char)a;

            while (k && !isSufPref(pattern, newStr, k))
                k--;

            table[q][a] = k;
        }
    }

    return table;
}

vector<int> matchByFA(string s, string pattern)
{
    vector<vector<int>> transition_function;

    transition_function = create_transition_func(pattern);

    int m = pattern.size();

    vector<int> pos;

    int q = 0;
    for (int i = 0; i < s.size(); i++)
    {
        q = transition_function[q][s[i]];

        if (q == m)
            pos.push_back(i - m + 1);
    }

    return pos;
}

int main()
{

    string s = "hello world, how wor being? wor";
    string pattern = "wor";

    vector<int> pos = matchByFA(s, pattern);

    for (auto e : pos)
        cout << e << ' ';
    cout << nl;

    return 0;
}