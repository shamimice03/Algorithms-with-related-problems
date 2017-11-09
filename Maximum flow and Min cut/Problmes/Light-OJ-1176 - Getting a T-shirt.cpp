#include<bits/stdc++.h>
using namespace std;
#define int long long
#define V 206

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{

    bool visited[V];
    memset(visited, 0, sizeof(visited));


    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
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


int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;


    int rGraph[V][V]={0};

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;


    while (bfs(rGraph, s, t, parent))
    {

        int path_flow = INT_MAX;
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

  main(){

  int test;
    cin>>test;

  for(int tt=1; tt<=test; tt++){
  int  node,edge;
  int  s,t,u,v,c;

    cin>>node>>edge;

  int  graph[V][V]={0};


    string a,b;

    map<string,int>mm;

    mm["XXL"]=51;
    mm["XL"] =52;
    mm["M"]  =53;
    mm["S"]  =54;
    mm["L"]  =55;
    mm["XS"] =56;

    s=57;
    t=58;

    for(int i=51; i<=56; i++){
        graph[s][i]=node;
    }

    for(int i=1; i<=edge; i++){

        cin>>a>>b;
        graph[mm[a]][i] = 1;
        graph[mm[b]][i] = 1;
        graph[i][t] = 1;

    }

    printf("Case %d: ",tt);
    int solve = fordFulkerson(graph,s,t);

    if(solve == edge) printf("YES\n");
    else printf("NO\n");

    }

    return 0;
}



