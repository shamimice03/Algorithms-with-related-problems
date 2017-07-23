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
#define   SIZE           10010
using namespace std;

int visit[SIZE];
vector<int>edges[SIZE];
vector<int>Top_sort;

void dfs_topsort(int u){

    visit[u]=1;

    for(int i=0; i<edges[u].size(); i++){

        int v=edges[u][i];
        if(visit[v]==0) dfs_topsort(v);
    }
   Top_sort.pb(u);
}

void dfs(int u){

   visit[u]=1;

   for(int i=0; i<edges[u].size(); i++){

      int v=edges[u][i];
      if(visit[v]==0) dfs(v);
   }
}

int main()
{
   int tc,n,m,u,v;
   cin>>tc;
   for(int j=1; j<=tc; j++){

      cin>>n>>m;

      for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[u].pb(v);
      }

      for(int i=0; i<=n; i++) visit[i]=0;
      for(int i=1; i<=n; i++){
        if(visit[i]==0) dfs_topsort(i);
      }

      for(int i=0; i<=n; i++) visit[i]=0;
      int c=0;
      for(int i = Top_sort.size()-1;   i >= 0;    i--){
        int v=Top_sort[i];
        if(visit[v]==0){
         c++;
         dfs(v);
      }
      }

      printf("Case %d: %d\n",j,c);

      Top_sort.clear();

      for(int i=0; i<=n; i++)edges[i].clear();
   }
      return 0;
}
