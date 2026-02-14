#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> adj_list(node);
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 0; i < node; i++)
        sort(adj_list[i].rbegin(), adj_list[i].rend());
    
    int query;
    cin >> query;
    while (query--)
    {
        int src;
        cin >> src;
        if (adj_list[src].size() == 0)
        {
            cout << -1 << endl;
        }
        else 
        {
            for (int x : adj_list[src])
                cout << x << " ";
            cout << endl;
        }
    }
    
    return 0;
}

