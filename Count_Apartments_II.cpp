#include<bits/stdc++.h>
using namespace std;

int row, col;
vector<vector<char>> graph;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < col &&
            graph[x][y] == '.' && !visited[x][y]);
}

int dfs(int sr, int sc)
{
    int count = 1;
    visited[sr][sc] = true;
    for(auto d : dir)
    {
        int cr = sr + d.first;
        int cc = sc + d.second;
        if(valid(cr, cc))
            count += dfs(cr, cc);
    }
    return count;
}

int main()
{
    cin >> row >> col;
    graph.assign(row, vector<char>(col));
    visited.assign(row, vector<bool>(col, false));
    for (auto &row : graph)
        for (char &ch : row)
            cin >> ch;
    
    vector<int> vec;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if(valid(i, j))
            {
                int count = dfs(i, j);
                vec.push_back(count);
            }
    sort(vec.begin(), vec.end());
    if (vec.empty()) cout << 0 << endl;
    for(int x : vec) cout << x << " ";
    cout << endl;

    return 0;
}