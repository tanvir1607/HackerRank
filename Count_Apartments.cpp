#include <bits/stdc++.h>
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

void dfs(int sr, int sc)
{
    visited[sr][sc] = true;
    for (auto d : dir)
    {
        int cr = sr + d.first;
        int cc = sc + d.second;
        if (valid(cr, cc))
            dfs(cr, cc);
    }
}

int main()
{
    cin >> row >> col;
    graph.assign(row, vector<char>(col));
    visited.assign(row, vector<bool>(col, false));
    for (auto &row : graph)
        for (char &ch : row)
            cin >> ch;

    int count = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (valid(i, j))
                count++, dfs(i, j);
    cout << count << endl;

    return 0;
}