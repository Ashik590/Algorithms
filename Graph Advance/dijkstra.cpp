#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define infinity INT_MAX

struct Node
{
    vector<pair<int, int>> adj;
    int distance;
    int prev;
};

void dijkstra(int vertices, int src, vector<Node> &nodes)
{
    for (int i = 0; i < vertices; i++)
    {
        nodes[i].distance = infinity;
        nodes[i].prev = -1;
    }

    nodes[src].distance = 0;

    set<pair<int, int>> st;
    for (int i = 0; i < vertices; i++)
        st.insert({nodes[i].distance, i});

    while (st.size())
    {
        auto v_it = st.begin();
        int v = v_it->second;

        st.erase(v_it);

        for (auto &[u, vu_w] : nodes[v].adj)
        {
            auto it = st.find({nodes[u].distance, u});
            if (it != st.end() && nodes[u].distance > nodes[v].distance + vu_w)
            {
                nodes[u].distance = nodes[v].distance + vu_w;
                nodes[u].prev = v;
                st.erase(it);
                st.insert({nodes[u].distance, u});
            }
        }
    }
}

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

    dijkstra(vertices, src, nodes);

    for (int i = 0; i < vertices; i++)
        cout << nodes[i].distance << ' ';
    cout << nl;

    return 0;
}