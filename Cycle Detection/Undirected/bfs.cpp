// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// Sample Input:
// Enter no of Nodes: 5
// Enter no of Edges: 4
// Enter the node followed by node connected to it:
// 0 1
// 0 2
// 0 3
// 2 4

// Sample Output:
// 1
// Explanation: 0->1->2->4->2 is a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool bfsCheck(int node, vector<int> &vis, vector<int> adj[], int V)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbour : adj[node])
            {
                if (neighbour != parent)
                    if (vis[neighbour])
                        return true;
                    else
                    {
                        q.push({neighbour, node});
                        vis[neighbour] = 1;
                    }
            }
        }
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (bfsCheck(i, vis, adj, V))
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
    bool ans = obj.isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}