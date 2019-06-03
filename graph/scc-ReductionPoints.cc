void dfs(int u, int fa)
{
    low[u] = dfn[u] = ++dfs_block;
    S.push(u);
1   bool flag = false;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])
                bridge++;
        }
        else if(v != fa || flag)
            low[u] = min(low[u], low[v]);
2       if(v == fa) flag = true;
    }
    if(low[u] == dfn[u])
    {
        ++scc_cnt;
        while(1)
        {
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}
void find_scc()
{
    init();
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i, -1);
}
for(int i = 1; i <= n; i++)
    for(int j = 0; j < G[i].size(); j++)
    {
        int v = G[i][j];
        if(sccno[i] != sccno[v])
        {
            M[sccno[i]].push_back(sccno[v]);
            M[sccno[v]].push_back(sccno[i]);
        }
    }
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    memset(vis, 0, sizeof(vis));
    vis[s] = 1; dis[s] = 0; last_node = s; ret = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < M[u].size(); i++)
        {
            int v = M[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                if(dis[v] > ret)
                {
                    ret = dis[v];
                    last_node = v;
                }
                q.push(v);
            }
        }
    }
}
    bfs(1);
    bfs(last_node);