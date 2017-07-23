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
#define   SIZE           30050
using namespace std;

vector<pii>edges[SIZE];
int dis[SIZE];
int vis[SIZE];


void bfs(int src){

     int u,v;
     vis[src]=1;
     dis[src]=0;
     queue<int>q;
     q.push(src);

     while(!q.empty()){

         u= q.front();
        q.pop();
        for(int i=0; i<edges[u].size(); i++){

             v=edges[u][i].first;

            if(vis[v]==0){
                vis[v]=1;
                dis[v]=dis[u]+edges[u][i].second;

                q.push(v);
            }
        }
     }

}

int main()
{
    int t,n,u,v,w;

    scanf("%d",&t);

    for(int i=1; i<=t; i++){



        scanf("%d",&n);
        for(int p=0; p<=n; p++){ vis[p]=0; edges[p].clear(); }
        for(int j=0; j<n-1; j++){
        scanf("%d %d %d",&u,&v,&w);

        edges[u].push_back(mp(v,w));
        edges[v].push_back(mp(u,w));

        }

        int src=0;
        bfs(src);

        for(int j=0; j<n; j++){
            if(dis[src]<dis[j]) src=j;
            vis[j]=0;
        }


        bfs(src);



      printf("Case %d: %d\n",i,*max_element(dis,dis+n));

    }

    return 0;
}
