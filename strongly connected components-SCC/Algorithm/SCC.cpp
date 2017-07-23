#include<bits/stdc++.h>
#define   inf            100000000000000000
#define   X              first
#define   Y              second
#define   B              begin()
#define   E              end()
#define   mp             make_pair
#define   pb             push_back
#define   loop1(i,n)     for(int i=1; i<=(n); i++)
#define   loop2(j,n)     for(int j=1; j<=(n); j++)
#define   loop0(i,n)     for(int i=0; i<(n); i++)
#define   valid(nx,ny)   nx>=1 && nx<=8 && ny>=1 && ny<=8
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           100
using namespace std;

vector<int>edges[SIZE],Redges[SIZE],component[SIZE];
int visited[SIZE];
stack <int> stk;

void dfs(int u){

      visited[u]=1;

      for(int i=0; i<edges[u].size(); i++){
            int v=edges[u][i];
        if(visited[v]==0){
            dfs(v);
        }
      }
     stk.push(u);
}

void dfs2(int u, int mark){

    component[mark].pb(u);  /// Node Save kortesi...
    visited[u]=1;
    for(int i=0; i<Redges[u].size(); i++){

         int v=Redges[u][i];
         if(visited[v]==0){
            dfs2(v,mark);
         }
    }

}

int main()
{
    int n,m,u,v,mark=0;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[u].pb(v);
        Redges[v].pb(u);/// Revese edges nisi ..SCC r jonno.

    }

    memset(visited, 0, sizeof(visited));
///top sort
    for(int i=0; i<=n; i++){

        if(visited[i]==0)
            dfs(i);
    }

    memset(visited, 0,sizeof(visited));

    while(!stk.empty()){

        int u=stk.top();
        stk.pop();

        if(visited[u]==0){

            mark=mark+1;///Component number ditesi mark use kore.
            dfs2(u,mark);
        }
    }

    for(int i=1; i<=mark; i++){
        for(int j=0; j<component[i].size(); j++) cout<<component[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
