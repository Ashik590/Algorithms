#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long
#define infinity INT_MAX

vector<vector<int>> floyd_warshall(vector<vector<int>> &adj_mat, vector<vector<int>> &inter)
{
    int v = adj_mat.size();

    vector<vector<int>> dist(v, vector<int>(v, infinity));

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (adj_mat[i][j] != -1)
            {
                dist[i][j] = adj_mat[i][j];
                inter[i][j] = i;
            }

    for (int i = 0; i < v; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] != infinity && dist[k][j] != infinity && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    inter[i][j] = k;
                }
            }

    return dist;
}

void pathRecurse(int src, int dst, vector<int> &path, vector<vector<int>> &inter)
{
    if (inter[src][dst] == -1)
        return;
    else if (inter[src][dst] == src)
        path.push_back(src);
    else
    {
        pathRecurse(src, inter[src][dst], path, inter);
        pathRecurse(inter[src][dst], dst, path, inter);
    }
}

vector<int> getPath(int src, int dst, vector<vector<int>> &inter)
{
    vector<int> path;

    pathRecurse(src, dst, path, inter);

    if (path.size())
        path.push_back(dst);

    return path;
}

int main()
{
    optimize();

    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj_mat(v, vector<int>(v, -1));

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj_mat[x][y] = w;
    }

    vector<vector<int>> inter(v, vector<int>(v, -1));

    vector<vector<int>> dist = floyd_warshall(adj_mat, inter);

    // for (auto r : dist)
    // {
    //     for (auto e : r)
    //         cout << e << ' ';
    //     cout << nl;
    // }

    vector<int> path = getPath(4, 4, inter);

    for (auto e : path)
        cout << e << ' ';
    cout << nl;

    return 0;
}