struct node
{
    int fir, sec;
    bool operator < (node a) const {
        if(fir != a.fir) return fir < a.fir;
        return sec < a.sec;
    }
};
void dfs(int u, int fa)
{
    low[u] = pre[u] = ++dfs_block;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > pre[u])
                all[co++] = node{u, v};
        }
        else if(v != fa)
            low[u] = min(low[u], low[v]);
    }
}