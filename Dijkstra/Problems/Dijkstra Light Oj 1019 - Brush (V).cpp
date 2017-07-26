#include<bits/stdc++.h>
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
const int Size=1234;
vector<int>edges[Size],mm[Size];

int cost[Size];
int parent[Size];


void Clear(){

    for(int i=0; i<=Size; i++){
        edges[i].clear();
        mm[i].clear();
    }

}


int Dijkstra(int str, int des){

  for(int i=1; i<=Size; i++){
      parent[i]=-1;
      cost[i]=inf;
  }

  priority_queue< pii, vector<pii>, greater<pii> > pq; // Vector<pii> , greater<pii> its for enqueue ... decreasing to increasing///
  pq.push(make_pair(0,str));
  cost[str]=0;

   while(!pq.empty()){
       int u=pq.top().second;
       if(u==des) break;
       pq.pop();
       for(int i=0; i<edges[u].size(); i++){
          int v=edges[u][i];
          if(cost[u]+mm[u][i]<cost[v]){
              cost[v]=cost[u]+mm[u][i];
              parent[v]=u;
              pq.push(make_pair(cost[v],v));
          }
       }
   }
   int y=des;
   if(parent[des]==-1){cout<<"Impossible"<<endl; return -1;}
   return cost[y];
}

int main()
{
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
    int n,e,u,v,w,s,d;

    cin>>n>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v>>w;
        edges[u].push_back(v);
        edges[v].push_back(u);

        mm[u].push_back(w);
        mm[v].push_back(w);

    }
    cout<<"Case "<<t<<": ";
    int cost=0;
    cost=Dijkstra(1,n);

    if(cost!=-1) cout<<cost<<endl;

    Clear();

    }
    return 0;
}
