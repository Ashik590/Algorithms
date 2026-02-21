// Defining articulation points of undirected graph efficiently

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
    int low;
};

void DFS_recurse(vector<Node> &nodes, int &time, int ind, vector<int> &articulation_points)
{
    nodes[ind].color = 'G';
    nodes[ind].start = ++time;
    nodes[ind].low = nodes[ind].start;

    bool isArticulationPoint = 0;

    int cntChild = 0;
    for (auto e : nodes[ind].adj)
    {
        if (nodes[e].color == 'W')
        {
            cntChild++;

            nodes[e].prev = ind;
            DFS_recurse(nodes, time, e, articulation_points);
            nodes[ind].low = min(nodes[ind].low, nodes[e].low);

            if (nodes[e].low >= nodes[ind].start)
                isArticulationPoint = 1;
        }
        else if (nodes[ind].prev != e)
            nodes[ind].low = min(nodes[ind].low, nodes[e].start);
    }

    nodes[ind].finish = ++time;
    nodes[ind].color = 'B';

    if (nodes[ind].prev == -1)
    {
        isArticulationPoint = 0;
        if (cntChild > 1)
            isArticulationPoint = 1;
    }

    if (isArticulationPoint)
        articulation_points.push_back(ind);
}

vector<int> DFS(vector<Node> &nodes)
{
    for (auto &v : nodes)
    {
        v.color = 'W';
        v.prev = -1;
        v.start = -1;
        v.finish = -1;
        v.low = -1;
    }

    int time = 0;
    vector<int> articulation_points;

    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].color == 'W')
            DFS_recurse(nodes, time, i, articulation_points);
    }

    return articulation_points;
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

    vector<int> articulation_points = DFS(nodes);

    for (auto e : articulation_points)
        cout << e << ' ';
    cout << nl;

    return 0;
}