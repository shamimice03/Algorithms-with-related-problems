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
#define   SIZE           20000+10
using namespace std;

int n,m,mark,in,out;
int belong[SIZE],visited[SIZE],indegree[SIZE],outdegree[SIZE];
vector<int>edges[SIZE],Redges[SIZE];
stack <int> stk;


void dfs1(int u){

      visited[u]=1;
      for(int i=0; i<edges[u].size(); i++){
        int v=edges[u][i];
        if(visited[v]==0) dfs1(v);
      }

      stk.push(u);
}

void dfs2(int u, int mark){

      visited[u]=1;
      belong[u]=mark;

      for(int i=0; i<Redges[u].size(); i++){
        int v=Redges[u][i];

        if(visited[v]==0) dfs2(v,mark);
      }
}

void dfs3(int u){

   visited[u]=1;
   for(int i=0; i<edges[u].size(); i++){

    int v=edges[u][i];

    if(belong[u] != belong[v]){
        indegree[belong[v]]++;
        outdegree[belong[u]]++;
    }
    if(visited[v]==0) dfs3(v);

   }

}


void allclear(){

       for(int i=0; i<=n+1; i++){
        visited[i]=0;
        belong[i]=-1;
        indegree[i]=0;
        outdegree[i]=0;
        edges[i].clear();
        Redges[i].clear();
       }

       mark=0;
       in=0;
       out=0;
}

int main()
{
    int test,u,v;
    sf(test);

    loop1(j,test){
      sff(n,m);
      allclear();

      loop0(i,m){
          sff(u,v);
          edges[u].pb(v);
          Redges[v].pb(u);
      }

     for(int i=1; i<=n; i++) {if(visited[i]==0) dfs1(i);}

     for(int i=0; i<=n; i++) visited[i]=0;

     while(!stk.empty()){

        int u=stk.top();
        stk.pop();

        if(visited[u]==0){  mark=mark+1; dfs2(u,mark);}
     }

     for(int i=0; i<=n; i++) visited[i]=0;

     for(int i=1; i<=n; i++) {if(visited[i]==0) dfs3(i);}

     for(int i=1; i<=mark && mark>1; i++){

       if(indegree[i]==0) in++;
       if(outdegree[i]==0)out++;

     }

    printf("Case %d: %d\n",j,max(in,out));

    }

    return 0;
}

