/*

TEST CASE :

8 12
3 7 2
2 6 2
5 2 3
6 1 3
5 3 3
7 1 3
6 4 1
8 2 1
7 4 3
8 3 3
1 5 500
4 8 500
1 8


*/



#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
#define Size 1200
#define inf 100000000

int node,edge;
vector<pi>edges[Size];
int rgraph[Size][200],CutGraph[Size][200];



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


void dfs(int s, bool visited[])
{

    visited[s] = true;
    for (int i = 0; i <=node; i++)
       if (rgraph[s][i] && !visited[i])
           dfs(i, visited);
}




int fordFulkerson(int s,int t){


          memset(rgraph,0,sizeof rgraph);
          memset(CutGraph,0,sizeof CutGraph);

          for(int i=0; i<=node+10; i++)
            for(int j=0; j<edges[i].size(); j++){
                  int v=edges[i][j].first;
                  int c=edges[i][j].second;
                  rgraph[i][v]=c;
                  CutGraph[i][v]=c;
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

    bool visited[node+10];
    memset(visited, false, sizeof(visited));
    dfs(s, visited);

    int CutEdge=0;

    cout<<endl;
    cout<<"Min Cut Edges : "<<endl;
    for (int i = 0; i <= node+10; i++)
      for (int j = 0; j <=edge; j++){
         if (visited[i] && !visited[j] && CutGraph[i][j]){
              cout<<i<<" --> "<<j<<" cost--> "<<CutGraph[i][j]<<endl;
         }
      }

    cout<<endl;
    cout<<"Maximum Flow --> ";

    return max_flow;

}

int main()
{
    int u,v,c,s,t;


    cin>>node>>edge;


//    for(int i=0; i<=1500; i++){
//            edges[i].clear();
//    }


    for(int i=0; i<edge; i++)
    {
    cin>>u>>v>>c;
    edges[u].push_back(make_pair(v,c));
    //edges[v].push_back(make_pair(u,c));
    }


    cin>>s>>t;
    cout<<fordFulkerson(s,t)<<endl;


    return 0;

}

