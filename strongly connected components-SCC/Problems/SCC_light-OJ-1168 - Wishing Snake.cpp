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
#define   sf(a)          scanf("%d",&a)
#define   sff(a,b)       scanf("%d %d",&a,&b)
#define   MOD            1000000007
#define   SIZE           100000
using namespace std;

int n,m,u,v,mark=0,node_num;
vector<int>edges[SIZE],Redges[SIZE],component[SIZE];
int node[SIZE],belong[SIZE],test=0;
stack<int>stk;
int visited[SIZE],com_vis[SIZE];

void allclear(){

    for(int i=0; i<=node_num+1; i++){
        edges[i].clear();
        Redges[i].clear();
        visited[i]=0;
        belong[i]=0;
    }
   for(int i=0; i<=mark+1; i++){
        component[i].clear();
        com_vis[i]=0;
    }
}


void dfs1(int u){

     visited[u]=1;
     for(int i=0; i<edges[u].size(); i++){
        int v=edges[u][i];
        if(visited[v]==0){
          dfs1(v);
        }
     }
          stk.push(u);
}

void dfs2(int u, int mark){
    visited[u]=1;
    belong[u]=mark;

    for(int i=0; i<Redges[u].size(); i++){

        int v= Redges[u][i];
        if(visited[v]==0) dfs2(v,mark);
    }

}

void dfs3(int u){

   com_vis[u]=1;

   if(component[u].size()>1) {test=1; return;}

   for(int i=0; i<component[u].size(); i++){
       int v=component[u][i];
          dfs3(v);
   }

}

int main()
{

   int t;
   sf(t);
   for(int k=1; k<=t; k++){

    sf(n);


    memset(node, -1, sizeof(node));
    node_num=0;
    node[0]=node_num;
    for(int i=1; i<=n; i++){
        sf(m);
     for(int i=1; i<=m; i++){

        sff(u,v);

        if(node[u]==-1) node[u]=++node_num;
        if(node[v]==-1) node[v]=++node_num;

        edges[node[u]].pb(node[v]);
        Redges[node[v]].pb(node[u]);
    }
   }

   for(int i=0; i<node_num; i++){

        if(visited[i]==0)
             dfs1(i);
   }

   for(int i=0; i<=node_num; i++) visited[i]=0;
   while(!stk.empty()){

       int u= stk.top();
       stk.pop();

       if(visited[u]==0) {
            mark=mark+1;
            dfs2(u,mark);
       }
   }

   for(int i=0; i<node_num; i++)
     for(int j=0; j<edges[i].size(); j++){

          int u= edges[i][j];

          if(belong[i] != belong[u])
            component[belong[i]].pb(belong[u]);
     }

     test=0;
     dfs3(belong[0]);

     if(test==0){

        for(int i=1; i<=mark; i++){
            if(com_vis[i]==0) test=1;

        }
     }

     printf("Case %d: ",k);
     if(test==0)printf("YES\n");
     else printf("NO\n");
     allclear();
     mark=0;
     test=0;

  }

}
