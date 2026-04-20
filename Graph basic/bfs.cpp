// BFS with undirected graph

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

struct Node
{
    char data;
    vector<int> adj;
    char color;
    int distance;
    int prev;
};

void BFS(vector<Node> &nodes, int st)
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
        int ind = Q.front();
        Q.pop();

        for (auto e : nodes[ind].adj)
        {
            if (nodes[e].color == 'W')
            {
                nodes[e].color = 'G';
                nodes[e].distance = nodes[ind].distance + 1;
                nodes[e].prev = ind;

                Q.push(e);
            }
        }

        nodes[ind].color = 'B';
    }
}

// After performing BFS
vector<int> printPath(vector<Node> &nodes, int st, int end)
{
    vector<int> path;

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

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<Node> nodes(n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // Taking 0-based indexed vertices

        nodes[x].adj.push_back(y);
        nodes[y].adj.push_back(x);
    }

    BFS(nodes, 0);

    vector<int> path = printPath(nodes, 0, 7);

    for (auto e : path)
        cout << e << ' ';
    cout << nl;

    return 0;
}