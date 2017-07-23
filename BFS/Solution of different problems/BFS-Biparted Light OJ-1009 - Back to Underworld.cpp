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

vector<int>edges[200005];
set<int>ss;
int visited[200005];
int color[200005];
int c2=0,c3=0;
set<int>::iterator it;


void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    color[s]=2;
    ++c2;
    while(!Q.empty()){
      int u=Q.front();

        Q.pop();
        for(int i=0; i<edges[u].size(); i++){

              int v=edges[u][i];
             if(visited[v]==0){
                Q.push(v);
                visited[v]=1;
                if(color[u]==2){
                   color[v]=3;
                   ++c3;
                }
                else {color[v]=2; ++c2;}

            }

        }
    }
}

void clr(int n){

     for(it=ss.B; it!=ss.E; it++){
        int s=*it;
        edges[s].clear();
        visited[s]=0;
        color[s]=0;
    }
}

int main()
{

    int t,n,e,v,u,start;


    scanf("%d",&t);
    for(int j=1; j<=t; j++){
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&u,&v);

        edges[u].push_back(v);
        edges[v].push_back(u);
        ss.insert(u);
        ss.insert(v);
    }
    int total=0;

    for(it=ss.B; it!=ss.E; it++)
    {
        int p=*it;
        if(visited[p]==0){
            BFS(p);
          total+=max(c2,c3);
          c2=0;c3=0;
        }
    }
       printf("Case %d: %d\n",j,total);
       c2=0,c3=0;
        clr(n);
       ss.clear();

    }

    return 0;
}

