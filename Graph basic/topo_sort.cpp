// Topological sort of a DAG (Directed Acyclic Graph)

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
        else if (nodes[e].color == 'G')
            throw invalid_argument("This is not DAG!");

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';
    topo_sort.push_back(ind);
}

vector<int> DFS(vector<Node> &nodes)
{
    vector<int> topo_sort;

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
            DFS_recurse(nodes, time, i, topo_sort);
    }

    reverse(topo_sort.begin(), topo_sort.end());

    return topo_sort;
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

    for (auto e : topo_sort)
        cout << e << ' ';
    cout << nl;

    return 0;
}