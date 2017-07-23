#include<bits/stdc++.h>
#define inf 100000000000000000
#define X first
#define Y second
#define B begin()
#define E end()
#define mp make_pair
#define pb push_back
#define loop1(i,n) for(int i=1; i<=(n); i++)
#define loop2(j,n) for(int j=1; j<=(n); j++)
#define loop0(i,n) for(int i=0; i<(n); i++)
#define loop(i,n) for(int i=0; i<=(n); i++)
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
#define pii pair<int, int>
#define Size 10000
using namespace std;
int cost[Size][Size],dis[Size];
vector<pii>edges;
int n,e;

void bell(int s,int node){

   for(int i=0; i<=node; i++) dis[i]=inf;
   dis[s]=0;

   for(int j=0; j<node-1; j++){
     for(int i=0; i<edges.size(); i++){
          if(dis[edges[i].X] + cost[edges[i].X][edges[i].Y] < dis[edges[i].Y] )
            dis[edges[i].Y] = dis[edges[i].X] + cost[edges[i].X][edges[i].Y];
      }
   }

         for(int i=0; i<edges.size(); i++){
             if(dis[edges[i].X] + cost[edges[i].X][edges[i].Y] < dis[edges[i].Y] ){
             cout<<"possible"<<endl;
             return;
             }
         }

         cout<<"not possible"<<endl;

}

int main()
{

   int u,v,w,str,des,t;
   cin>>t;
   while(t--){
   edges.clear();
   cin>>n>>e;

   for(int i=0; i<e; i++){
     cin>>u>>v>>w;
     edges.pb({u,v});
     cost[u][v]=w;
   }

   bell(0,n);

   }

    return 0;
}



