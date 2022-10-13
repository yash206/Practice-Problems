#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> tree[N];
int depth[N];
void dfs(int vertex, int parent)
{

    for (int child : tree[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    int diameter = 0;
    int diamN;
    for (int i = 1; i <= n; i++)
    {
        if (diameter < depth[i])
        {
            diameter = depth[i];
            diamN = i;
        }
        depth[i] = 0;
    }
    dfs(diamN, 0);
    diameter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (diameter < depth[i])
        {
            diameter = depth[i];
        }
    }

    cout << diameter << endl;
    return 0;
}


//Find the diameter of a tree 

/*
Input:-

5
1 2
1 3
2 4
2 5

Output:-

3
*/
