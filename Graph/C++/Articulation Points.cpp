#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int T, low[N], dis[N], art[N];
vector<int> g[N];
void dfs(int u, int pre = 0)
{
    low[u] = dis[u] = ++T;
    int child = 0;
    for (auto v : g[u])
    {
        if (!dis[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dis[u] && pre != 0)
                art[u] = 1;
            ++child;
        }
        else if (v != pre)
            low[u] = min(low[u], dis[v]);
    }
    if (pre == 0 && child > 1)
        art[u] = 1;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    cout << "Articulation Points are : ";
    for (int i = 1; i <= n; i++)
        if (art[i] != 0)
        {
            cout << i << " ";
            ans++;
        }
    if (ans == 0)
        cout << "NULL" << endl;
    cout << "\nTotal number of articulation points are : " << ans << '\n';
    return 0;
}

/*
Explanation:
    Tarjan Algorithm is used to check whether is graph is strongly connected or not
    it also find its uses to check the articulation points ,
    articulation points are those points whose removal increase in the number of connected components
    of graph , it also find its use in finding bridges , bridges are those edge whose removal increase in the
    number of connected components.
    Here we have implemented Tarjan's Algorithm to find articulation points.

Program Features:
    In this program first user will give the number of vertices the graph has
    then they will give the input for the number of edges of the graph
    then they will give the details of the edge that is they will provide two inputs for
    the number of edge lines. This two inputs will connect two vertices with an edge.
    Then at the last output will be the articulation points the graph has.

Time Complexity : O(V+E)        where (V,E) = number of vertices,number of edges

Space Complexity: O(V)          where V = number of vertices


Input :
        5 5
        1 2
        1 3
        3 2
        1 4
        4 5
Output :
        Articulation Points are : 1 4
*/
