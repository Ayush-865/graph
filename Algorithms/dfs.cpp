/*

Space Complexity: O(n)+O(n)+O(n) ~ O(n)
Time Complexity: -

    0
   /|\
  1 2 3
    |
    4

Sample Input:
Enter no of Nodes: 5
Enter no of Edges: 4
Enter the node followed by node connected to it:
0 1
0 2
0 3
2 4

Sample Output:
0 1 2 4 3
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) // V is no of nodes, adj[] is adjacency list
{
    vector<int> vis(V, 0);
    vector<int> ans;
    int start = 0;
    dfs(start, adj, vis, ans);
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

    vector<int> ans = dfsOfGraph(V, adj);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    return 0;
}