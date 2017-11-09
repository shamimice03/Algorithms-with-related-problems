#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define V 206

bool bfs(LL rGraph[V][V], LL s, LL t, LL parent[])
{

    bool visited[V];
    memset(visited, 0, sizeof(visited));


    queue <LL> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        LL u = q.front();
        q.pop();

        for (LL v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}


LL fordFulkerson(LL graph[V][V], LL s, LL t)
{
    LL u, v;


    LL rGraph[V][V]={0};

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    LL parent[V];

    LL max_flow = 0;


    while (bfs(rGraph, s, t, parent))
    {

        LL path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);

        }


        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }


        max_flow += path_flow;
    }


    return max_flow;
}


int main()
{

    LL test;
    scanf("%lld",&test);

    for(LL tt=1; tt<=test; tt++){
    LL capa,node,edge,x[105];
    LL s,t,u,v,c;

    //taking capacitors


    scanf("%lld",&capa);

   LL graph[V][V]={0};

   LL g=capa;

    for(LL i=1; i<=capa; i++){
        scanf("%lld",&u);
        graph[i][i+capa]=u;
        x[i]=i+capa;
    }


    scanf("%lld",&edge);


    for(LL i=0; i<edge; i++){

        cin>>u>>v>>c;
        graph[x[u]][v]=c;
    }

    LL ss,ttt,start,des;
    scanf("%lld %lld",&ss,&ttt);


    LL source = 0,sink=205;
    for(LL i=1; i<=ss; i++){
        scanf("%lld",&start);
        graph[source][start]=INT_MAX;
    }

 for(LL i=1; i<=ttt; i++){
        scanf("%lld",&des);
        graph[x[des]][sink]=INT_MAX;
    }

    printf("Case %lld: %lld\n",tt,fordFulkerson(graph,source,sink));


    }

    return 0;
}


