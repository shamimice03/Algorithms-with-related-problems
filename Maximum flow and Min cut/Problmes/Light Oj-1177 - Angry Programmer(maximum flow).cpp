#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
#define Size 1200
#define inf 100000000
int node,edge;
vector<pi>edges[Size];
int rgraph[Size][100];



bool bfs(int s,int t,int parent[]){

    bool visited[node+10];
    memset(visited,0,sizeof visited);
    memset(parent,0,sizeof parent);

    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    while(!q.empty()){


        int u = q.front();
        q.pop();

           for (int v=0; v<=node; v++)
        {
            if (visited[v]==false && rgraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t]==true);
}




int fordFulkerson(int s,int t){


          memset(rgraph,0,sizeof rgraph);


          for(int i=0; i<=node+10; i++)
            for(int j=0; j<edges[i].size(); j++){
                  int v=edges[i][j].first;
                  int c=edges[i][j].second;
                  rgraph[i][v]=c;
              }


              int parent[node];
              int max_flow=0;

         while(bfs(s,t,parent)){


            int path_flow = INT_MAX,u;


            for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
            }


          for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
            }



            max_flow += path_flow;

         }

        return max_flow;
}





int main()
{
    int u,v,c,s,t;

    cin>>t;

    for(int tt=1; tt<=t; tt++){

    cin>>node>>edge;

    for(int i=0; i<=100; i++){
            edges[i].clear();
    }

    for(int i=2; i<node; i++){
        cin>>c;
        int p=i+node;
        edges[i].push_back(make_pair(p,c));
    }

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v>>c;
    edges[u+node].push_back(make_pair(v,c));
    edges[v+node].push_back(make_pair(u,c));
    }

    edges[1].push_back(make_pair(node+1,inf));
    edges[node].push_back(make_pair(node+node,inf));

    node+=node;
    printf("Case %d: ",tt);
    cout<<fordFulkerson(1,node)<<endl;

    }

    return 0;

}
