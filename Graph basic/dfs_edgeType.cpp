// DFS with directed graph, defining the type of edges

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

void DFS_recurse(vector<Node> &nodes, int &time, int ind, vector<pair<int, int>> treeEdges, vector<pair<int, int>> forwardEdges, vector<pair<int, int>> backEdges, vector<pair<int, int>> crossEdges)
{
    nodes[ind].color = 'G';
    nodes[ind].start = ++time;

    for (auto e : nodes[ind].adj)
    {
        if (nodes[e].color == 'W')
        {
            treeEdges.push_back({ind, e});
            nodes[e].prev = ind;
            DFS_recurse(nodes, time, e, treeEdges, forwardEdges, backEdges, crossEdges);
        }
        else if (nodes[e].color == 'G')
            backEdges.push_back({ind, e});
        else
        {
            if (nodes[e].start < nodes[ind].start)
                crossEdges.push_back({ind, e});
            else
                forwardEdges.push_back({ind, e});
        }
    }

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';
}

void DFS(vector<Node> &nodes, vector<pair<int, int>> treeEdges, vector<pair<int, int>> forwardEdges, vector<pair<int, int>> backEdges, vector<pair<int, int>> crossEdges)
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
            DFS_recurse(nodes, time, i, treeEdges, forwardEdges, backEdges, crossEdges);
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

    vector<pair<int, int>> treeEdges;
    vector<pair<int, int>> forwardEdges;
    vector<pair<int, int>> backEdges;
    vector<pair<int, int>> crossEdges;

    DFS(nodes, treeEdges, forwardEdges, backEdges, crossEdges);

    return 0;
}