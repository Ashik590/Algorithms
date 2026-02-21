/*

Consider the problem of what strategy to take when moving
your fingers over a keypad to dial a telephone number. You want to dial
using two fingers, which begin respectively on the and # keys. The ∗
objective is to devise a strategy so that the fingers take the least amount
of effort overall for dialing a full n digit number. You may assume that the
effort involved in moving one finger from one key to another is
proportional to the distance between the two keys, and that a finger will
remain hovering over a key until it is moved to the next key. (Use the
distance between keys as the Euclidean distance, and round to the nearest
1/2 to make the arithmetic easy. Eg. take the distance between keys next
to each other as 1 unit if it is a vertically or horizontally next to, and 1.5
units if diagonally i.e. √2 rounded to the nearest 1/2.)

*/

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

double calc_dist(int d1, int d2)
{
    int x1 = d1 % 3;
    int y1 = d1 / 3;

    int x2 = d2 % 3;
    int y2 = d2 / 3;

    int x_diff = abs(x1 - x2);
    int y_diff = abs(y1 - y2);

    double calc = sqrt(x_diff * x_diff + y_diff * y_diff);
    calc = round(calc * 2) / 2.0;

    return calc;
}

int main()
{
    cout << "Enter total #digits = ";
    int n;
    cin >> n;

    cout << "Enter digits (string) ->" << nl;
    string s;
    cin >> s;

    map<char, int> mapping;
    for (int i = 1; i <= 9; i++)
        mapping[i + '0'] = i - 1;

    mapping['*'] = 9;
    mapping['0'] = 10;
    mapping['#'] = 11;

    double dp[n + 1][12][12];

    for (int l = 0; l < 12; l++)
        for (int r = 0; r < 12; r++)
            dp[n][l][r] = 0;

    for (int i = n - 1; i >= 0; i--)
        for (int l = 0; l < 12; l++)
            for (int r = 0; r < 12; r++)
            {
                double distFromL = calc_dist(mapping[s[i]], l);
                double distFromR = calc_dist(mapping[s[i]], r);

                dp[i][l][r] = min(distFromL + dp[i + 1][mapping[s[i]]][r], distFromR + dp[i + 1][l][mapping[s[i]]]);
            }

    cout << dp[0][mapping['*']][mapping['#']] << nl;

    return 0;
}