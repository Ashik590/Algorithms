// DFS with directed graph

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

struct Node
{
    char data;
    vector<int> adj;
    char color;
    int start;
    int finish;
    int prev;
};

void DFS_recurse(vector<Node> &nodes, int &time, int ind)
{
    nodes[ind].color = 'G';
    nodes[ind].start = ++time;

    for (auto e : nodes[ind].adj)
        if (nodes[e].color == 'W'){
            nodes[e].prev = ind;
            DFS_recurse(nodes, time, e);
        }

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';
}

void DFS(vector<Node> &nodes)
{
    for (auto &v : nodes)
    {
        v.color = 'W';
        v.prev = -1;
        v.start = -1;
        v.finish = -1;
    }
    int time = 0;

    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].color == 'W')
            DFS_recurse(nodes, time, i);
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
    }

    DFS(nodes);

    return 0;
}