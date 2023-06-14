// Ford Fulkerson Algorithm to Find the Maximum Flow
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 1000005;
const int inf = 1e9;
int n, m, s, t, head[N], cur[N], cnt = 1, dis[N], ans;
bool vis[N];
struct node
{
    int next, to, cap;
} e[M];
void add(int x, int y, int z)
{
    e[++cnt].next = head[x];
    head[x] = cnt;
    e[cnt].to = y;
    e[cnt].cap = z;
}
bool bfs()
{
    memset(dis, 0, sizeof dis);
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (e[i].cap > 0 && !dis[y])
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    return dis[t];
}
int dinic(int x, int flow)
{
    if (x == t)
        return flow;
    int rest = flow, k;
    for (int i = cur[x]; i && rest; i = e[i].next)
    {
        cur[x] = i;
        int y = e[i].to;
        if (e[i].cap > 0 && dis[y] == dis[x] + 1)
        {
            k = dinic(y, min(rest, e[i].cap));
            if (!k)
                dis[y] = 0;
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    return flow - rest;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, 0);
    }
    while (bfs())
    {
        memcpy(cur, head, sizeof head);
        ans += dinic(s, inf);
    }
    cout << "Max Flow is:" << ans << endl;
    return 0;
}