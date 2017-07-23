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
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
#define pii pair<int, int>
using namespace std;
const int Size=123456;
map<int, vector<int> >edges,mm;
//map<pair<int, int>, int > mm;
long long cost[Size];
int parent[Size];

int Dijkstra(int str, int des){

  loop1(i,Size){ parent[i]=-1; cost[i]=inf;}

  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push(mp(0,str));
  cost[str]=0;

   while(!pq.empty()){

       int u=pq.top().Y;
       if(u==des) break;
       pq.pop();

       loop0(i,edges[u].size()){

          int v=edges[u][i];

          if(cost[u]+mm[u][i]<cost[v]){
              cost[v]=cost[u]+mm[u][i];
              parent[v]=u;
              pq.push(mp(cost[v],v));
          }
       }
   }
   int y=des;
   if(parent[des]==-1){cout<<"No path"<<endl; return -1;}
   else{
   vector<int>vec;
   vec.pb(des);

   while(str!=des){
       des=parent[des];
       vec.pb(des);
   }

   reverse(vec.B,vec.E);
   cout<<"Shortest path direction : ";
  loop0(i,vec.size()) cout<<vec[i]<<" ";
}
  cout<<endl;
  return cost[y];
}

int main()
{
    int n,e,u,v,w,s,d;

    cin>>n>>e;

    loop1(i,e)
    {
        cin>>u>>v>>w;
        edges[u].pb(v);
        edges[v].pb(u);

        mm[u].pb(w);
        mm[v].pb(w);

    }

    cin>>s>>d;
    int cost=0;
    cost=Dijkstra(s,d);

    if(cost!=-1) cout<<"Cost : "<<cost<<endl;

    return 0;
}
