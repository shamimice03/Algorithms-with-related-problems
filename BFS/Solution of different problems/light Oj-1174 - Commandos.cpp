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
#define   SIZE           105
using namespace std;

vector<int>edges[SIZE];
int dis1[SIZE],dis2[SIZE];
bool visited[SIZE];

void bfs(int st,int d[]){

     memset(visited, 0, sizeof(visited));
     visited[st]=1;
     queue<int>q;
     q.push(st);
     d[st]=0;

     while(!q.empty()){

        int u=q.front();
        q.pop();

        for(int i=0; i<edges[u].size(); i++){

            int v = edges[u][i];

            if(visited[v]==0){
                q.push(v);
                visited[v]=1;
                d[v]=d[u]+1;
            }
        }
     }

}

void clr(int a){

   for(int i=0; i<a; i++)
    edges[i].clear();
}

int main()
{
    int t,u,v,s,e,ans=-1,n,m;

    cin>>t;

    for(int i=1; i<=t; i++){

        memset(dis1, 0,sizeof(dis1));
        memset(dis2, 0,sizeof(dis2));
        cin>>n>>m;

        for(int j=0; j<m; j++){

            cin>>u>>v;

            edges[u].pb(v);
            edges[v].pb(u);

        }

        cin>>s>>e;

        bfs(s,dis1);
        bfs(e,dis2);

        for(int p=0; p<n; p++){
          ans= max(ans,dis1[p]+dis2[p]);
        }

        printf("Case %d: ",i);
        cout<<ans<<endl;
        ans=-1;

        clr(n);
    }



}
