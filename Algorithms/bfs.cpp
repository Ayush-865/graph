/*
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
0 1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]) // V is no of nodes, adj[] is adjacency list
{
    vector<int> vis(V, 0);
    vector<int> ans;
    vis[0] = 1; // since 0 based indexing so we initialize the vis[0]=1
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
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

    vector<int> ans = bfs(V, adj);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    return 0;
}