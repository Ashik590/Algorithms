// BFS with undirected graph and to know if there exist more than one minimum cost path

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
    int ways;
};

void BFS(vector<Node> &nodes, int st)
{
    for (auto &e : nodes)
    {
        e.color = 'W';
        e.distance = -1;
        e.prev = -1;
        e.ways = 0;
    }

    nodes[st].color = 'G';
    nodes[st].distance = 0;
    nodes[st].ways = 1;

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
                nodes[e].ways = nodes[ind].ways;

                Q.push(e);
            }
            else if (nodes[e].distance == nodes[ind].distance + 1)
                nodes[e].ways += nodes[ind].ways;
        }

        nodes[ind].color = 'B';
    }
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

    for (auto e : nodes)
        cout << e.ways << ' ';
    cout << nl;

    return 0;
}