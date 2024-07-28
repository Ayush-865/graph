/*
Topological Sort can be done on Directed Acyclic Graph (DAG)

Sample Input:
Enter no of Nodes: 4
Enter no of Edges: 3
Enter the node followed by node connected to it:
1 0
2 0
3 0

Sample output:
3 2 1 0
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, st);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int V, E;
    cout << "Enter no of Nodes: ";
    cin >> V;
    cout << "Enter no of Edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter the node followed by node connected to it: \n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topoSort(V, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}