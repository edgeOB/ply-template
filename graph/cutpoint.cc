void dfs(int u, int fa)
{
    int low[u] = pre[u] = ++dfs_block;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= pre[u])
                iscut[u] = true;
        }
        else if(v != fa)
            low[u] = min(low[u], pre[v]);
    }
    if(fa < 0 && child == 1) iscut[u] = false;
}