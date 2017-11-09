///********** C++ program for implementation of Ford Fulkerson algorithm**********///
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
#define Size 199
int node,edge;
vector<pi>edges[Size];
int rgraph[Size][100];


/// *******Finding a path******///////
bool bfs(int s,int t,int parent[]){

    bool visited[node+1];
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

///************************************///

int fordFulkerson(int s,int t){

          memset(rgraph,0,sizeof rgraph);


          for(int i=0; i<=node; i++)
            for(int j=0; j<edges[i].size(); j++){
                  int v=edges[i][j].first;
                  int c=edges[i][j].second;
                  rgraph[i][v]=c;
              }


              int parent[node+1];
              int max_flow=0;

         while(bfs(s,t,parent)){


            int path_flow = INT_MAX,u;

    ///********Finding lowest cost of a path**********///
            for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
            }
    ///***********************************************///




    ///***********Making residual Graph*************///
          for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            rgraph[u][v] -= path_flow; ///**Capacity baki ace koto**//
            rgraph[v][u] += path_flow; ///**Use hoise koto(ulta edge)**///
            }
   ///*************************************************///


            max_flow += path_flow;

         }

        return max_flow;

}

int main()
{
    int u,v,c,s,t;

    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v>>c;
        edges[u].push_back(make_pair(v,c));
    }

    cin>>s>>t;

    cout<<fordFulkerson(s,t)<<endl;

}
