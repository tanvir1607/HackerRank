// #include <bits/stdc++.h>
// using namespace std;

// int main() 
// {
//     int node, edge;
//     cin >> node >> edge;
//     vector<vector<int>> adj_list(node); 
//     while (edge--) 
//     {
//         int a, b;
//         cin >> a >> b;
//         adj_list[a].push_back(b);  
//     }

//     int query;
//     cin >> query;
//     while (query--) 
//     {
//         int src, dst;
//         cin >> src >> dst;

//         bool flag = false;
//         for (int child : adj_list[src]) 
//         {
//             if (child == dst)
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         cout << (flag || src == dst ? "YES" : "NO") << endl;
//     }

//     return 0;
// }





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
    }
    for (int i = 0; i < node; i++)
        sort(adj_list[i].begin(), adj_list[i].end());


    int query;
    cin >> query;
    while (query--) 
    {
        int src, dst;
        cin >> src >> dst;
        bool flag = binary_search(adj_list[src].begin(), adj_list[src].end(), dst);
        cout << (flag || src == dst ? "YES" : "NO") << endl;
    }

    return 0;
}