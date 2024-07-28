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

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
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

    vector<int> ans = topoSort(V, adj);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    return 0;
}