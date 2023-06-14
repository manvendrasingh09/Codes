// Edmonds Karp Algorithm to Find the Maximum Flow
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define inf 0x3f3f3f3f
#define maxn 0xfffffff
int n, m, s, t, cnt = 1, head[MAXN], dis[MAXN], vis[MAXN];
int a[MAXN][MAXN];
struct node
{
    int to, next, cap;
} e[MAXN * MAXN];
inline void add(int u, int v, int w)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].cap = w;
    e[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
    e[cnt].to = u;
    e[cnt].cap = 0;
    e[cnt].next = head[v];
    head[v] = cnt;
}
int bfs()
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + 1 && e[i].cap > 0)
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    if (dis[t] != inf)
        return 1;
    return 0;
}
int dfs(int u, int flow)
{
    if (u == t)
        return flow;
    int used = 0;
    for (int i = head[u]; i && flow; i = e[i].next)
    {
        int v = e[i].to;
        if (dis[v] == dis[u] + 1 && e[i].cap > 0)
        {
            int f = dfs(v, min(flow, e[i].cap));
            if (f)
            {
                flow -= f;
                used += f;
                e[i].cap -= f;
                e[i ^ 1].cap += f;
            }
        }
    }
    return used;
}
int dinic()
{
    int sum = 0;
    while (bfs())
    {
        sum += dfs(s, inf);
    }
    return sum;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    cout << "Max Flow is:" << dinic() << endl;
    return 0;
}