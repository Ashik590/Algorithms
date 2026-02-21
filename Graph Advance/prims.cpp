#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// prims is only for the undirected graph

struct Node
{
    int parent;
    int key;
    vector<pair<int, int>> adj;

    Node()
    {
        parent = -1;
        key = INT_MAX;
    }
};

void prims(int vertices, int src, vector<Node> &nodes)
{
    set<pair<int, int>> st;

    nodes[src].key = 0;

    for (int i = 0; i < vertices; i++)
        st.insert({nodes[i].key, i});

    vector<bool> isInMST(vertices, false);

    while (st.size())
    {
        auto v_it = st.begin();
        int v = v_it->second;
        st.erase(v_it);

        isInMST[v] = true;

        for (auto &u : nodes[v].adj)
        {
            auto it = st.find({nodes[u.first].key, u.first});

            if (!isInMST[u.first] && it != st.end() && nodes[u.first].key > u.second)
            {
                nodes[u.first].key = u.second;
                nodes[u.first].parent = v;
                st.erase(it);
                st.insert({nodes[u.first].key, u.first});
            }
        }
    }
}

int main()
{
    int edges, vertices;
    cin >> vertices >> edges;

    vector<Node> nodes(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        nodes[u].adj.push_back({v, w});
        nodes[v].adj.push_back({u, w});
    }

    int src;
    cin >> src;

    vector<Node> trees(vertices);

    prims(vertices, src, nodes);

    for (int i = 0; i < vertices; i++)
        trees[i].adj.push_back({nodes[i].parent, nodes[i].key});

    for (auto v : trees)
    {
        cout << v.adj[0].first << " " << v.adj[0].second << nl;
    }

    return 0;
}