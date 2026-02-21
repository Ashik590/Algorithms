// Defining Strongly Connected Components by DFS in a directed graph

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

void DFS_recurse(vector<Node> &nodes, int &time, int ind, vector<int> &topo_sort)
{
    nodes[ind].color = 'G';
    nodes[ind].start = ++time;

    for (auto e : nodes[ind].adj)
        if (nodes[e].color == 'W')
        {
            nodes[e].prev = ind;
            DFS_recurse(nodes, time, e, topo_sort);
        }

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';
    topo_sort.push_back(ind);
}

vector<int> DFS(vector<Node> &nodes)
{
    for (auto &v : nodes)
    {
        v.color = 'W';
        v.prev = -1;
        v.start = -1;
        v.finish = -1;
    }
    int time = 0;

    vector<int> topo_sort;

    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].color == 'W')
            DFS_recurse(nodes, time, i, topo_sort);
    }

    reverse(topo_sort.begin(), topo_sort.end());

    return topo_sort;
}

void DFS_recurse_SCC(vector<Node> &nodes, int &time, int ind, vector<int> &SCC)
{
    SCC.push_back(ind);

    nodes[ind].color = 'G';
    nodes[ind].start = ++time;

    for (auto e : nodes[ind].adj)
        if (nodes[e].color == 'W')
        {
            nodes[e].prev = ind;
            DFS_recurse_SCC(nodes, time, e, SCC);
        }

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';
}

vector<vector<int>> DFS_SCC(vector<Node> &nodes, vector<int> topo_sort)
{
    for (auto &v : nodes)
    {
        v.color = 'W';
        v.prev = -1;
        v.start = -1;
        v.finish = -1;
    }
    int time = 0;

    vector<vector<int>> SCCs;
    for (int i = 0; i < topo_sort.size(); i++)
    {
        if (nodes[topo_sort[i]].color == 'W')
        {
            vector<int> SCC;
            DFS_recurse_SCC(nodes, time, topo_sort[i], SCC);
            SCCs.push_back(SCC);
        }
    }

    return SCCs;
}

vector<Node> to_transpose(vector<Node> nodes)
{
    vector<Node> nodes_T(nodes.size());

    for (int i = 0; i < nodes.size(); i++)
        for (auto e : nodes[i].adj)
            nodes_T[e].adj.push_back(i);

    return nodes_T;
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

    vector<int> topo_sort = DFS(nodes);

    vector<Node> nodes_T = to_transpose(nodes);

    vector<vector<int>> SCCs = DFS_SCC(nodes_T, topo_sort);

    for (auto scc : SCCs)
    {
        for (auto v : scc)
            cout << v << ' ';
        cout << nl;
    }

    return 0;
}