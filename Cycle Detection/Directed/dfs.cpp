/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Sample Input:
Enter no of Nodes: 4
Enter no of Edges: 4
Enter the node followed by node connected to it:
0 1
1 2
2 3
3 3

Sample Output:
1
Explanation: 3 -> 3 is a cycle
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 2;

        for (auto neighbour : adj[node])
        {
            if (vis[neighbour] == 2)
                return true;
            else if (vis[neighbour] != 1)
                if (dfsCheck(neighbour, vis, adj))
                    return true;
        }

        vis[node] = 1;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] != 1)
                if (dfsCheck(i, vis, adj))
                    return true;
        }

        return false;
    }
};

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
    Solution obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}