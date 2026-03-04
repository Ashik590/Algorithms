#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

/*
    Disclaimer :
    - If you dont use modulo q, then its O(n + m)
    - But you do use, then its O(n * m) in worst case
    - BUT generally, in practice, its O(n + m)
    - Reducing collision is main priority
    - Not using q, it will Memory exceed easily if m is little bit large
    - Then the Memory time complexity = O(d ^ m)
    - m = length of the pattern, d = unique characters

    - I am using q modulo as its part of the algorithm
*/

const long q = 1e9 + 7;

long pows(long num, long power)
{
    long ans = 1;

    for (int i = 0; i < power; i++)
        ans *= num;

    return ans;
}

vector<int> robin_karp(string s, string pattern)
{
    int n = s.size(), m = pattern.size();

    if (n < m)
        throw new invalid_argument("String is smaller than Pattern itself");

    long offset = pows(256, m - 1);

    vector<long> hashes(n - m + 1, 0);

    for (int i = 0; i < m; i++)
        hashes[0] += pows(256, m - i - 1) * s[i];

    for (int i = 1; i < n - m + 1; i++)
    {
        hashes[i] = (hashes[i - 1] - offset * s[i - 1]) * 256 + s[i + m - 1];
    }

    long pattern_hash = 0;

    for (int i = 0; i < m; i++)
        pattern_hash += pows(256, m - i - 1) * pattern[i];

    vector<int> pos;

    for (int i = 0; i < hashes.size(); i++)
        if (hashes[i] == pattern_hash)
            pos.push_back(i);

    return pos;
}

int main()
{

    string s = "Hello world how world you?";
    string pattern = "world how";

    vector<int> pos = robin_karp(s, pattern);

    for (auto e : pos)
        cout << e << ' ';
    cout << nl;

    return 0;
}