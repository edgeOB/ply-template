void dfs(int u)
{
    low[u] = dfn[u] = ++dfs_block;
    S.push(u);
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!sccno[v])
            low[u] = min(low[u], low[v]);
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