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

    string pattern = "aba";
    string text = "abbaaba";
    vector<char> alphabets = {'a', 'b'};

    int m = pattern.size();

    vector<vector<int>> transitions(m, vector<int>(alphabets.size(), -1));

    for (int q = 0; q <= m; q++)
        for (int i = 0; i < alphabets.size(); i++)
        {
            ik = 1 + min(m, q + 1);
        }

    return 0;
}