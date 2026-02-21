#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

struct Node
{
    char data;
    char color;
    int distance;
    int prev;
};

void BFS(vector<Node> &nodes, vector<vector<int>> &adj_mat, int st)
{
    for (auto &e : nodes)
    {
        e.color = 'W';
        e.distance = -1;
        e.prev = -1;
    }

    nodes[st].color = 'G';
    nodes[st].distance = 0;

    queue<int> Q;
    Q.push(st);

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for (int u = 0; u < nodes.size(); u++)
        {
            if (adj_mat[v][u] && nodes[u].color == 'W')
            {
                nodes[u].color = 'G';
                nodes[u].distance = nodes[v].distance + 1;
                nodes[u].prev = v;

                Q.push(u);
            }
        }

        nodes[v].color = 'B';
    }
}

// After performing BFS
vector<int> printPath(vector<Node> &nodes, int st, int end)
{
    vector<int> path;
    if (st == end)
        return path;

    while (st != end)
    {
        if (end == -1)
        {
            path.clear();
            return path;
        }

        path.push_back(end);
        end = nodes[end].prev;
    }

    path.push_back(st);

    reverse(path.begin(), path.end());

    return path;
}

int getMaxFlow(vector<Node> &nodes, vector<vector<int>> &adj_mat, int src, int dst)
{
    int maxFlow = 0;

    vector<int> path;
    do
    {
        BFS(nodes, adj_mat, src);
        path = printPath(nodes, src, dst);

        int bottleNeck = INT_MAX;

        for (int i = 0; i < (int)path.size() - 1; i++)
            bottleNeck = min(bottleNeck, adj_mat[path[i]][path[i + 1]]);

        for (int i = 0; i < (int)path.size() - 1; i++)
        {
            adj_mat[path[i]][path[i + 1]] -= bottleNeck;
            adj_mat[path[i + 1]][path[i]] += bottleNeck;
        }

        if (bottleNeck != INT_MAX)
            maxFlow += bottleNeck;
    } while (path.size());

    return maxFlow;
}

int main()
{
    int n;
    cin >> n;
    vector<Node> nodes(n);

    int src, dst, edges;

    cin >> src >> dst >> edges;

    vector<vector<int>> adj_mat(n, vector<int>(n, 0));

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_mat[u][v] += w;
    }

    cout << getMaxFlow(nodes, adj_mat, src, dst) << nl;

    return 0;
}