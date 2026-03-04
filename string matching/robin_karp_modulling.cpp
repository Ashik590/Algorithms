#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

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
    - Assuming there are only 256 characters possible
*/

const long q = 1e9 + 7;

vector<int> robin_karp(string s, string pattern)
{
    int n = s.size(), m = pattern.size();

    if (n < m)
        throw new invalid_argument("String is smaller than Pattern itself");

    ll offset = 1;

    for (int i = 0; i < m - 1; i++){
        offset *= 256;
        offset %= q;
    }

    vector<ll> hashes(n - m + 1, 0);

    ll new_offset = 1;
    for (int i = 0; i < m; i++)
    {
        hashes[0] += new_offset * s[m - i - 1];
        hashes[0] %= q;

        new_offset = (new_offset * 256) % q;
    }

    for (int i = 1; i < n - m + 1; i++)
    {
        hashes[i] = (hashes[i - 1] - offset * s[i - 1]) * 256 + s[i + m - 1];
        hashes[i] %= q;

        if (hashes[i] < 0)
            hashes[i] += q;
    }

    ll pattern_hash = 0;

    new_offset = 1;
    for (int i = 0; i < m; i++)
    {
        pattern_hash += new_offset * pattern[m - i - 1];
        pattern_hash %= q;

        new_offset = (new_offset * 256) % q;
    }

    vector<int> pos;

    for (int i = 0; i < hashes.size(); i++)
    {
        if (hashes[i] == pattern_hash)
        {
            bool cond = 1;

            for (int j = 0; j < m; j++)
                if (s[i + j] != pattern[j])
                    cond = 0;

            if (cond)
                pos.push_back(i);
        }
    }

    return pos;
}

int main()
{

    string s = "Hello world how world is you very world how you?";
    string pattern = "world how world";

    vector<int> pos = robin_karp(s, pattern);

    for (auto e : pos)
        cout << e << ' ';
    cout << nl;

    return 0;
}