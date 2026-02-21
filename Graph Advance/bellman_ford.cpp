#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

struct Node
{
    vector<pair<int, int>> adj;
    int distance;

    Node()
    {
        distance = INT_MAX;
    }
};

bool bellmanFord(int vertices, int src, vector<Node> &nodes)
{
    nodes[src].distance = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        for (int v = 0; v < vertices; v++)
            if (nodes[v].distance != INT_MAX)
                for (auto &[u, vu_w] : nodes[v].adj)
                {
                    if (nodes[u].distance > nodes[v].distance + vu_w)
                        nodes[u].distance = nodes[v].distance + vu_w;
                }
    }

    for (int v = 0; v < vertices; v++)
        if (nodes[v].distance != INT_MAX)
            for (auto &[u, vu_w] : nodes[v].adj)
            {
                if (nodes[u].distance > nodes[v].distance + vu_w)
                {
                    cout << "Undefined Graph" << nl;
                    return false;
                }
            }

    return true;
}

// directed graph

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Node> nodes(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        nodes[u].adj.push_back({v, w});
    }

    int src;
    cin >> src;

    bellmanFord(vertices, src, nodes);

    for (int i = 0; i < vertices; i++)
        cout << nodes[i].distance << ' ';
    cout << nl;

    return 0;
}